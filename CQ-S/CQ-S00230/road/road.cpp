/*

15:16
有可能被卡常，一会儿回来再说吧 

*/
#include<bits/stdc++.h>
using namespace std;
namespace Sasuke{
	#define int long long
//	#define ll long long
	#define maxm 200005
	#define maxv 1000005
	#define maxn 1005
	#define mod 1000000007
	#define inf 0x3f3f3f3f3f3f
	#define msk cerr
	int cas,T,n,m,k,N,ans=inf;
	int v[maxm],fa[maxm];
	struct node{int x,y,w;}a[maxv],b[maxm],s[15][maxm],t[maxm];
	bool cmp(node x,node y){return x.w<y.w;}
	int Getfa(int x){return fa[x]==x?x:fa[x]=Getfa(fa[x]);}
	void Init(){
		N=m;m=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=N;i++){
			int x=a[i].x,y=a[i].y,w=a[i].w;
			int fx=Getfa(x),fy=Getfa(y);
			if(fx==fy)continue;
			fa[fx]=fy;s[0][++m]=a[i];
		}
	}
	struct srh{
		int id,i,w;
		friend bool operator <(srh x,srh y){return x.w>y.w;}
	};
	priority_queue<srh>q;
	int Kruskal(int lim,int sum){//lim表点个数 
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int tot=0;
		while(q.size()&&tot<lim-1){
			if(ans<=sum)break;
			srh p=q.top();q.pop();
			int id=p.id,i=p.i,w=p.w,x=s[id][i].x,y=s[id][i].y;
			int fx=Getfa(x),fy=Getfa(y);
			i++;
			if(id){
				if(i<=n)q.push({id,i,s[id][i].w});
			}else if(i<n)q.push({id,i,s[id][i].w});
			if(fx==fy)continue;
//			msk<<"add:"<<id<<" "<<i<<" :"<<x<<" "<<y<<" "<<w<<"\n";
			fa[fx]=fy;sum+=w;tot++;
		}
//		msk<<tot<<" "<<sum<<"\n";
		return sum;
	}
	signed main(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].w;
		sort(a+1,a+m+1,cmp);Init();//先把有用边预处理出来 
		for(int i=1;i<=k;i++){
			cin>>v[i];
			for(int j=1;j<=n;j++){
				int w;cin>>w;s[i][j]={i+n,j,w};
			}
			sort(s[i]+1,s[i]+n+1,cmp); 
		}
//		for(int ss=1;ss<=1;ss++)
		for(int ss=0;ss<1<<k;ss++){
			int sum=0,cnt=0;
			while(q.size())q.pop();
			q.push({0,1,s[0][1].w});
			for(int i=1;i<=k;i++)if(ss>>i-1&1){
				sum+=v[i];cnt++;q.push({i,1,s[i][1].w});
			}
			int res=Kruskal(n+cnt,sum);
//			msk<<ss<<":"<<res<<" "<<sum<<"\n";
			ans=min(ans,res); 
		}
		cout<<ans;
		return 0;
	}
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Sasuke::main();
	return 0; 
} 
