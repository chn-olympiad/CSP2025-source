//16:37
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int Rd;

inline Rd read(){Rd xxx=0,yyy=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}

const int maxn=10015,maxm=1000005;
const ll inf=0x3f3f3f3f3f3f3f3f;

int n,m,k,tot,cnt,bt,sz;
struct node{
	int u,v;ll w;
	bool operator <(const node&T)const{return w<T.w;}
}e[maxm],ne[maxn],b[maxn*10+maxm][2],a[20][maxn];
ll c[maxn];
int f[maxn];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void add_(){
	bt=0,sz=cnt;
	for(int i=1;i<=cnt;i++)b[i][0]=ne[i];
}void add(int x){
	bt^=1;
	int l=1,r=1;
	for(int i=1;i<=sz+n;i++){
		if(l<=sz&&(r>n||b[l][bt^1].w<a[x][r].w)){
			b[i][bt]=b[l][bt^1];
			l++;
		}else{
			b[i][bt]=a[x][r];
			r++;
		}
//		cout<<b[i][bt].w<<' ';
	}
	sz+=n;
}
void init(){
	for(int i=1;i<=n+k;i++)f[i]=i;
}
ll gt(int tt){
	init();
	ll ret=0;
	for(int i=1,ct=0;ct!=n-1+tt;i++){
		int f1=find(b[i][bt].u),f2=find(b[i][bt].v);
//		cout<<b[i][bt].u<<' '<<b[i][bt].v<<' '<<b[i][bt].w<<endl;
		if(f1!=f2){
//			cout<<'g'<<endl;
			ret+=b[i][bt].w;
			f[f1]=f2;
			++ct;
		}
	}
	return ret;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1);
	ll ans=0;
	
	for(int i=1;i<=m&&cnt!=n-1;i++){
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2)
			{f[f1]=f2,ne[++cnt]=e[i],ans+=e[i].w;}
	}
	
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j].u=n+i,a[i][j].v=j,a[i][j].w=read();
		sort(a[i]+1,a[i]+n+1);
	}
	for(int i=1;i<(1<<k);i++){
		tot=0;
		add_();
		ll h=0;
		int tt=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				tt++;
				add(j);
				h+=c[j];
			}
		}
		ans=min(ans,h+gt(tt));
	}
	cout<<ans;
	return 0;
}
