#include<bits/stdc++.h>
using namespace std;
int n,m,id,ans1,ans2;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			id=i;
			break;
		}
	}
	if(id%m!=0){
		ans1=id/m+1;
		if(ans1%2==1)ans2=id%m;
		else ans2=m-id%m+1;
	}else{
		ans1=id/m;
		if(ans1%2==1)ans2=m;
		else ans2=1;
	}
	cout<<ans1<<' '<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
