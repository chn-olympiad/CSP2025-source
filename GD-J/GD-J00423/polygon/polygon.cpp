#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005,mod=998244353,maxv=5001;
int n;
int a[N],dp[N],g[N];
int ans=0;
inline void adt(int &x,int y){x+=y;(x>=mod)&&(x-=mod);}
inline int ad(int x,int y){x+=y;return (x>=mod?x-mod:x);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	g[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			for(int j=a[i]+1;j<=maxv;j++) adt(dp[i],g[j]);
			adt(ans,dp[i]);
		}
		for(int j=maxv;j>=0;j--) adt(g[min(maxv,j+a[i])],g[j]);
	}
	cout<<ans<<'\n';
	return 0;
}

