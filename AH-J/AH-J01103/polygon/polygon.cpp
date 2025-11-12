#include<bits/stdc++.h>
using namespace std;

int n,a[5005],ans,MOD=998244353;
int jc(int x){
	int ans=1;
	for(int i=2;i<=x;i++) ans=ans*i%MOD;
	return ans;
}
int c(int n,int m){
	if(n==m) return 1;
	return jc(m)/(jc(n)*jc(m-n))%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	//bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(a[i]!=1) flag=0;
	}
	if(n==1||n==2) cout<<0;
	if(n==3){
		if(a[1]+a[2]+a[3]>=max(a[1],max(a[2],a[3]))) ans++;
		cout<<ans;
	}
	//if(flag==1){
		for(int i=3;i<=n;i++){
			ans=(ans+c(i,n))%MOD; 
		}
		cout<<ans;
	//}	 
	return 0;
}

