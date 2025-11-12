#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5005];
long long ans=0;
bool fun(int i,int m){
	int sum=0,maxx=-1;
	for(int j=i;j<=m;j++){
		sum+=a[j];
		maxx=max(maxx,a[j]*2);
	}
	if(maxx<sum) return true;
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(fun(i,j))ans=(ans+1+MOD)%MOD;
		}
	}
	cout<<ans%MOD;
	return 0;
}
