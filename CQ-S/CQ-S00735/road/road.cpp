#include<bits/stdc++.h>
#define int long long
#define double long double
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define per(i,r,l) for(int i=(r),i##end=(l);i>=i##end;--i)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int maxn=1e4+20,maxm=1e6+10,maxk=1024+10,mod=998244353,inf=1e18;
inline int ksm(int x,int k,int mod=mod){
	int ans=1;
	for(x=x%mod;k;k>>=1,x=x*x%mod) if(k&1) ans=ans*x%mod;
	return ans;
}

int n,m,k,ans=inf,f[maxn],tot[maxk],b[20],a[20][maxn];
array<signed,3> edge[maxm],eg[maxk][maxn];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m) cin>>edge[i][1]>>edge[i][2]>>edge[i][0];
	rep(i,1,k){
		cin>>b[i];
		rep(j,1,n) cin>>a[i][j];
	}
	sort(edge+1,edge+m+1);
	rep(i,1,n) f[i]=i;
	rep(i,1,m) if(find(edge[i][1])!=find(edge[i][2]))
		f[f[edge[i][1]]]=f[edge[i][2]],eg[0][++tot[0]]=edge[i];
	rep(sub,1,(1<<k)-1){
		int sub1=sub&(sub-1);
		rep(i,1,tot[sub1]) edge[i]=eg[sub1][i];
		rep(j,1,k) if(sub>>j-1&1){
			rep(i,1,n) edge[tot[sub1]+i]={(signed)a[j][i],(signed)i,(signed)(n+j)};
			break;
		}
		rep(i,1,n+k) f[i]=i;
		sort(edge+1,edge+tot[sub1]+n+1);
		rep(i,1,tot[sub1]+n) if(find(edge[i][1])!=find(edge[i][2]))
			f[f[edge[i][1]]]=f[edge[i][2]],eg[sub][++tot[sub]]=edge[i];
	}
	rep(sub,0,(1<<k)-1){
		int sum=0;
		rep(i,1,k) if(sub>>i-1&1) sum+=b[i];
		rep(i,1,tot[sub]) sum+=eg[sub][i][0];
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
