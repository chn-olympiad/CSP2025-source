/*
出发！前进！ 
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
/*
cirno /se /se
furina /se /se
yanami /se /se
yamada /se /se
sayaka /se /se
konata /se /se
蓝仙未未 /se /se 
*/
namespace TYX_YNXK{
	#define il inline
	#define vd void
	#define bl bool
	#define ll long long
	#define ull unsigned ll
	#define db double
	#define ldb long db
	#define pii pair<int,int>
	#define fi first
	#define se second
	#define MP make_pair
	#define pb push_back
	#define N 100005
	#define INF
	#define DEBUG cerr<<"\tfurina begin:\n"
	#define END cerr<<"\tyanami end.\n"
	#define c ch=getchar()
	il unsigned read(){
		unsigned x=0;char c;
		for(;ch<48||ch>57;c);
		for(;ch>47&&ch<58;c)x=(x<<3)+(x<<1)+(ch^48);
		return x;
	}
	#undef c
	int T,n,a[N][3],tong[3],ans;
	il vd solve(){
		n=read(),tong[0]=tong[1]=tong[2]=ans=0;vector<int>P[3];
		for(int i=1;i<=n;i++){
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])++tong[0],ans+=a[i][0],P[0].pb(a[i][0]-max(a[i][1],a[i][2]));
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])++tong[1],ans+=a[i][1],P[1].pb(a[i][1]-max(a[i][0],a[i][2]));
			else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1])++tong[2],ans+=a[i][2],P[2].pb(a[i][2]-max(a[i][0],a[i][1]));
		}
		int mx=max({tong[0],tong[1],tong[2]});
		if(mx>n/2){
			int id=0;
			if(tong[0]==mx)id=0;else if(tong[1]==mx)id=1;else id=2;
			sort(P[id].begin(),P[id].end());
			for(int i=0;i<mx-n/2;i++)ans-=P[id][i];
		}printf("%d\n",ans);
	}
	il vd clear(){
		
	}
	signed main(){
		for(T=read();T--;)solve(),clear();
		return 0;
	}
}signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	TYX_YNXK::main();
	return 0;
}/*
y^2=ax^3+bx+c 椭圆曲线保佑
TL: 1.0s
ML: 512MB
*/
/*
开题！
每个人可以分配到三个部门，且每个部门不能分配超过 n/2 个成员。
注意到我们贪心地先选最大，然后从最大抽出变化量最小的即可。因为 >n/2 意味着另外的那个一定不会超。
感谢 T1，信心++

居然还写假了一次 /kk 
*/
