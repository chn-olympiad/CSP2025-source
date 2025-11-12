#include <bits/stdc++.h>
#define ll long long 

using namespace std;
const int N = 1e5+5;
int T;

int n,rg,ans;
struct node{
	int a,b,c;
}mem[N];
bool cmp(node x,node y){
	if(x.a==y.a)return max(x.b,x.c)<max(y.b,y.c);
	return x.a<y.a;
}

namespace sol_tx{
	inline bool check(int k){
		int res=0;
		for(int i=1; i<=k; ++i){
			res+=mem[i].a;
		}
		int cntb=0,cntc=0;
		for(int i=k+1; i<=n; ++i){
			if(mem[i].b>mem[i].c){
				res+=mem[i].b;
				++cntb;
			}else if(mem[i].b>mem[i].c){
				if(cntc>cntb)++cntb;
				else ++cntc;
				res+=mem[i].b;
			}
			else {
				res+=mem[i].c;
				++cntc;
			}
			if(cntb>rg||cntc>rg)return 0;
		}
		ans=max(ans,res);
		return 1;
	}
	void calc(){
		sort(mem+1,mem+n+1,cmp);
		//printf("kmj");
		int l=0,r=rg,mid;
		while(l<=r){
			mid=((l+r)>>1);
			if(check(mid)){
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
	}
	void solve(){
		ans=-1;
		rg=(n>>1);
		for(int i=1; i<=n; ++i){
			cin>>mem[i].a>>mem[i].b>>mem[i].c;
		}
		calc();
		for(int i=1; i<=n; ++i){
			swap(mem[i].a,mem[i].b);
		}
		calc();
		for(int i=1; i<=n; ++i){
			swap(mem[i].a,mem[i].c);
		}
		calc();
		cout<<ans<<"\n";
	}
}
namespace sol_dp{
	const int M = 205;
	int dp[M][M];//表示给A分配 i 个，B 分配 j 个的最大收益
	inline int mx3(int a,int b,int c){
		return max(max(a,b),c);
	}
	void solve(){
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; ++i){
			cin>>mem[i].a>>mem[i].b>>mem[i].c;
		}
		rg=n>>1;
		for(int i=1; i<=n; ++i){
			for(int j=min(i,rg); j>=0; --j){
				for(int k=min(i-j,rg); k>=0; --k){
					if(i-j-k>rg)continue;
					int delc=(i-j-k>0?dp[j][k]+mem[i].c:0);
					int dela=(j?dp[j-1][k]+mem[i].a:0);
					int delb=(k?dp[j][k-1]+mem[i].b:0);
					dp[j][k]=mx3(delc,dela,delb);
				}
			}
		}
		ans=0;
		for(int i=1; i<=rg; ++i){
			for(int j=1; i+j<=n; ++j){
				if(j>rg||(n-i-j)>rg)continue;
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=200)sol_dp::solve();
		else sol_tx::solve();
	}
	return 0;
}