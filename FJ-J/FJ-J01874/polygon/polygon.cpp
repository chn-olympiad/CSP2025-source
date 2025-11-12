#include<bits/stdc++.h>
using namespace std;
//#define int long long
int mod=998244353;
int n;
int a[5005];
int fang[25000002];
int d[5005];
int cmp(int a,int b){
	return a<b;
}
int f;
int ans;
int g[5005][5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=d[i-1]+a[i];
		f=(f&&a[i]==1);
	}
	if(f){
		for(int i=1;i<=n;i++){
			g[i-1][0]=1;
			for(int j=1;j<=i;j++){
				g[i][j]=g[i-1][j]+g[i-1][j-1];
				g[i][j]%=mod;
			}
		}
		for(int i=3;i<=n;i++){
			ans+=g[n][i];
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	a[n+1]=d[n];
	fang[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=d[i];j>=a[i];j--){
			fang[j]=(fang[j]+fang[j-a[i]])%mod;
		}
		for(int j=a[i]*2+1;j<=a[i+1]*2;j++){
			ans=(ans+fang[j])%mod;
		}
	}
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

*/







