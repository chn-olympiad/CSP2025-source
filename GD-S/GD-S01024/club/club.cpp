#include<bits/stdc++.h>
#define int long long
#define rint register int
#define endl '\n'
using namespace std;
const int N=1e5+5;
struct node{
	int k,x;
}a[N][4];
int T,n,ans;
int c[4];
int k1[N],k2[N],k3[N];
inline bool cmp(const node& a,const node& b){
	return a.x>b.x;
}
inline bool cmp2(int a,int b){
	return a>b;
}
inline int dfs(const rint& dep){
	if(dep==n+1) return 0;
	int res=0;
	for(rint i=1;i<4;++i){
		int k=a[dep][i].k,x=a[dep][i].x;
		if(c[k]==(n>>1)) continue;
		++c[k];
		res=max(res,dfs(dep+1)+x);
		--c[k];
	}
	return res;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=30){
			for(rint i=1;i<=n;++i){
				for(rint j=1;j<4;++j){
					cin>>a[i][j].x;
					a[i][j].k=j;
				}
				stable_sort(a[i]+1,a[i]+4,cmp);
			}	
			memset(c,0,sizeof c);
			cout<<dfs(1)<<endl;
		}else{
			for(rint i=1;i<=n;++i)
				cin>>k1[i]>>k2[i]>>k3[i];
			stable_sort(k1+1,k1+1+n,cmp2);
			stable_sort(k2+1,k2+1+n,cmp2);
			int ans=0;
			for(rint i=1;i<=(n>>1);++i) ans+=k1[i];
			for(rint i=1;i<=(n>>1);++i) ans+=k2[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
