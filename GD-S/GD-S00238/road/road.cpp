#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	register int fh=1,nbr=0;
	register char ch=getchar();
	while((ch<'0'||ch>'9')&&(ch!='-')) ch=getchar();
	if(ch=='-') fh=-1,ch=getchar();
	while(ch>='0'&&ch<='9') nbr=nbr*10+(ch-'0'),ch=getchar();
	return fh*nbr;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	static int stk[21];
	register int top=0;
	while(x) stk[++top]=x%10,x=x/10;
	while(top) putchar(stk[top--]+'0');
}
int father[10004],siz[10004];
void init(int n){
	for(int i=1;i<=n;i++) father[i]=i,siz[i]=1;
}
int grand(int x){
	if(father[father[x]]==father[x]) return father[x];
	return father[x]=grand(father[x]);
}
bool merge(int x,int y){
	if(grand(x)==grand(y)) return false;
	if(siz[father[x]]<siz[father[y]]) swap(x,y);
	siz[father[x]]+=siz[father[y]];
	father[father[y]]=father[x];
	return true;
}
struct path{
	int u,v,w;
	path(){}
	path(int a,int b,int c){u=a,v=b,w=c;}
	bool operator < (const path x)const{
		return w<x.w;
	}
}mp[1000006],g[11][10004],e[20004][11];
int n,m,k,c[11],a[11][10004],sum,ans,num[1<<10],pri[11],val[11];
void get_num(int n){
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			num[i]+=((i&(1<<j))>0);
		}
	}
}
void calculate(int s,int now){
	int sum=(pri[num[s]]=pri[num[s]-1]+val[now]);
//	cout<<s<<' '<<now<<' '<<sum<<'\n';
	init(n);
	int ecnt=0;
//	cout<<s<<' '<<now<<' '<<num[s]<<'\n';
	for(int i=1,j=1;ecnt<n-1;){
		int nu,nv,nw;
		if(i<n&&e[i][num[s]-1].w<g[now][j].w) nu=e[i][num[s]-1].u,nv=e[i][num[s]-1].v,nw=e[i][num[s]-1].w,i++;
		else nu=g[now][j].u,nv=g[now][j].v,nw=g[now][j].w,j++;
//		cout<<nu<<' '<<nv<<' '<<nw<<' '<<i<<' '<<j<<'\n';
		if(!merge(nu,nv)) continue;
		e[++ecnt][num[s]]=path(nu,nv,nw);
		sum+=nw;
	}
	ans=min(ans,sum);
//	cout<<sum<<'\n';
	for(int j=now+1;j<=k;j++){
		calculate(s|(1<<(j-1)),j);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		mp[i]=path(u,v,w);
	}
	sort(mp+1,mp+1+m);
	int ecnt=0;
	init(n);
	for(int i=1;i<=m&&ecnt<n-1;i++){
		if(!merge(mp[i].u,mp[i].v)) continue;
		e[++ecnt][0]=mp[i];
		sum+=mp[i].w;
	}
	ans=sum;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
		int minlen=LLONG_MAX,pos;
		for(int j=1;j<=n;j++){
			if(a[i][j]<minlen) minlen=a[i][j],pos=j;
		}
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(j==pos) continue;
			g[i][++cnt]=path(pos,j,a[i][j]);
		}
		val[i]=c[i]+minlen;
		sort(g[i]+1,g[i]+cnt+1);
	}
//	cout<<sum<<'\n';
	get_num(k);
	for(int i=1;i<=k;i++){
		calculate((1<<(i-1)),i);
	}
	write(ans);
	return 0;
}
//Please let me pass.
