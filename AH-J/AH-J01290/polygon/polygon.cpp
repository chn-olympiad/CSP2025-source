#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5001];
int qzh[5001];
int f[5001];
int dfs(int i,int ans,int n){
	if(i==n){
		if(ans>a[n])return 1;
		else return 0;
	}
	return dfs(i+1,ans+a[i],n)+dfs(i+1,ans,n);
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(a,0,sizeof a);
	memset(qzh,0,sizeof qzh);
	memset(f,0,sizeof f);
	int n;
	cin>>n;
	if(n==3){
		int a1,b,c;
		cin>>a1>>b>>c;
		int q=max({a1,b,c});
		if(a1+b+c>2*q)cout<<1;
		else cout<<0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=qzh[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	if(qzh[n]==n){
		long long ans=0;
	    for(int i=3;i<=n;i++){
		   long long x=1,y=1;
		    for(int j=1;j<=i;j++){
			    x*=j;y*=(n-j+1);
			    x%=mod;y%=mod;
		    }
		    ans+=(y/x)%mod;
	    }
	    cout<<ans;
	}
	else {
		long long p=0;
		for(int i=3;i<=n;i++){
			p+=dfs(1,0,i);
		}
		cout<<p;
	}
    return 0;
}
