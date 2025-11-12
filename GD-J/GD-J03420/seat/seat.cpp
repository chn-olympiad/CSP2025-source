#include<bits/stdc++.h>
using namespace std;
int n,m,p,ans1,ans2;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(p==a[i]){
			p=i;
			break;
		}
	ans1=(p-1)/n+1;
	if(ans1%2) ans2=(p-1)%n+1;
	else ans2=n-(p-1)%n;
	cout<<ans1<<' '<<ans2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
