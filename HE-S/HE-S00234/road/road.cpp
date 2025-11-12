#include<bits/stdc++.h>
#define LL long long
#define popcnt(n) __builtin_popcount(n) 
using namespace std;
const int N=2e6+10,M=2e4+100;
//bool A;
struct nod{int a,b,c;}s[N],tmp[M];
int f[N],n,m,k,tot,c[100],vis[M];LL ans[M];
nod d[(int)1.5e3+10][(int)1e4+100],t[20][M];
inline int find(int a){
	if(f[a]==a)return a;
	return f[a]=find(f[a]);
}
inline bool cmp(const nod &x,const nod &y){return x.c<y.c;}
//bool B;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
//	cout<<fabs(&B-&A)/1024/1024<<"MB";
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	 
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>s[i].a>>s[i].b>>s[i].c;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			t[i][j]={i+n,j,x};
		}
		sort(t[i]+1,t[i]+1+n,cmp);
	}
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int a=find(s[i].a),b=find(s[i].b);
		if(a==b)continue;
		f[a]=b;d[0][++tot]=s[i];
		ans[0]+=s[i].c;
	}
	vis[0]=1;
	LL Ans=1e18;
	for(int s=0;s<(1<<k);s++){
		for(int i=1;i<=k;i++){
			if((s>>i-1)&1)ans[s]+=c[i];
		}
		Ans=min(Ans,ans[s]);
		int len=n+popcnt(s)-1;
		for(int i=1;i<=k;i++){
			if((s>>i-1)&1)continue;
			if(vis[s|(1<<i-1)]==1)continue;
			int l1=0,l2=0,tot=0;vis[s|(1<<i-1)]=1;
			while(l1<=len&&l2<=n){
				if(d[s][l1].c<=t[i][l2].c)tmp[++tot]=d[s][l1],l1++;
				else tmp[++tot]=t[i][l2],l2++;
			}
			while(l1<=len)tmp[++tot]=d[s][l1],l1++;
			while(l2<=n)tmp[++tot]=t[i][l2],l2++;
			for(int j=1;j<=n+k;j++)f[j]=j;
			int Len=0;
			for(int j=1;j<=tot;j++){
				int a=find(tmp[j].a),b=find(tmp[j].b);
				if(a==b)continue;
				f[a]=b;ans[s|(1<<i-1)]+=tmp[j].c;
				d[s|(1<<i-1)][++Len]=tmp[j];
				if(Len==len+1)break;
			}
		}
	}
	cout<<Ans;
	return 0;
}
