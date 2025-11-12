#include<bits/stdc++.h>
using namespace std;
int p=998244353;
int n,a[5001];
int c(int n,int m){
	if(n==m) return 1;
	int ans=1,now=m+1;
	for(int i=1;i<=n-m;i++){
		ans*=now;
		ans/=i;
		ans%=p;
		now++;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1]) cout<<"1"<<endl;
		else cout<<"0"<<endl;
		return 0;
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		ans+=c(n,i);
		ans%=p;
	}
	cout<<ans<<endl;
	return 0;
}
