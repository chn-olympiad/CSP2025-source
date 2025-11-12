#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,M=5e6+5,p=233,mod=998244353;
int n,q;
ll mi[M],ha[N][2],sum[2][M],ny[M];
string s[N][2],t[2];
ll getha(int f,int l,int r){
	ll w=sum[f][r];
	if(l>0)w=(w-sum[f][l-1]+mod)%mod;
	w=w*ny[l]%mod;
	return w;
}
ll poww(ll x,int y){
	ll res=1;
	while(y>0){
		if(y&1)res=res*x%mod;
		x=x*x%mod;y>>=1;
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	mi[0]=1;
	for(int i=1;i<=5000000;i++){
		mi[i]=mi[i-1]*p%mod;
	}
	ny[5000000]=poww(mi[5000000],mod-2);
	for(int i=4999999;i>=0;i--)ny[i]=ny[i+1]*p%mod;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<s[i][0].size();j++){
			ha[i][0]=(ha[i][0]+mi[j]*(s[i][0][j]-'a'))%mod;
			ha[i][1]=(ha[i][1]+mi[j]*(s[i][1][j]-'a'))%mod;
		}
	}
	while(q--){
		cin>>t[0]>>t[1];
		int l=0,r=0;
		for(int i=0;i<t[0].size();i++){
			if(t[0][i]!=t[1][i]){
				l=i;break;
			}
		}
		for(int i=t[0].size()-1;i>=0;i--){
			if(t[0][i]!=t[1][i]){
				r=i;break;
			}
		}
		sum[0][0]=0,sum[1][0]=0;
		for(int i=0;i<t[0].size();i++){
			if(i>0)sum[0][i]=sum[0][i-1],sum[1][i]=sum[1][i-1];
			sum[0][i]=(sum[0][i]+mi[i]*(t[0][i]-'a'))%mod;sum[1][i]=(sum[1][i]+mi[i]*(t[1][i]-'a'))%mod;
		}
		int ans=0;
		for(int k=r;k<t[0].size();k++){
			for(int j=1;j<=n;j++){
				int z=(int)k-s[j][0].size()+1;
				if(z<=l&&z>=0){
					if((getha(0,z,k)==ha[j][0])&&(getha(1,z,k)==ha[j][1])){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
