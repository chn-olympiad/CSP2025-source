#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fre(X) freopen(X".in","r",stdin),freopen(X".out","w",stdout)
#define Xueli return
#define Chang 0
using namespace std;
namespace did{
	int n,m;
	struct WZOI{
		int u,v,w;
	}a[1000006],b[10004],c[10004];
	int f[10055];
	int gf(int u){
		return f[u]==u?u:f[u]=gf(f[u]);
	}
	bool cmp(WZOI x,WZOI y){
		return x.w<y.w;
	}
	int k;
	int v[15][100005];
	int kru(){
		sort(a+1,a+m+1,cmp);
		int ans=0,cnt=0;
		for(int i=1;i<=n+k;i++)f[i]=i;
		for(int i=1;i<=m;i++){
			int u=gf(a[i].u),v=gf(a[i].v);
			if(u!=v){
				f[u]=v;
				b[++cnt]=a[i];
				ans+=a[i].w;
			}
		}
		return ans;
	}
	
	void init(){

	}
	void lusolve(){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
		int ans=kru();
		int t=n-1;
		m=n-1;
		for(int i=1;i<n;i++)a[i]=c[i]=b[i];
		for(int i=0;i<k;i++)for(int j=0;j<=n;j++)cin>>v[i][j];
		for(int i=0;i<(1<<k);i++){
			int he=0;
			int r=m;
			for(int j=0;j<k;j++){
				if(i&(1<<j)){
					he+=v[j][0];
					for(int f=1;f<=n;f++){
						a[++r]={n+j+1,f,v[j][f]};
					}
				}
			}
			m=r;
			he+=kru();
			m=t;
			for(int i=1;i<=m;i++)a[i]=c[i];
			ans=min(ans,he);
		}
		cout<<ans;
	}
}
signed main(){
	IOS();
	fre("road");
	int Q=1;
//	cin>>Q;
	did::init();
	while(Q--)did::lusolve();
//while(1);
	Xueli Chang;
}
//1s 512MB
//0.6687(O2)s 36MB
//为什么总感觉我写的像暴力 
/*
T2
先写的T2(因为图论)
先把MST凸出来。(其他边不会因为加边而更优)
然后搜i<(1<<k)
最后统计答案，取min
T2宝子你很乘哦!!! 
*/
