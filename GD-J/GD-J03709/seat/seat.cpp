#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int t,f,ans1,ans2;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			f=i;
			break;
		}
	}
	ans1=(f+n-1)/n;
	if(ans1%2==0){
		ans2=ans1*n-f+1;
	}else{
		ans2=m-(ans1*n-f);
	}
	cout<<ans1<<" "<<ans2<<endl;
	fclose(stdout);
	fclose(stdin);
	return 0;
}


