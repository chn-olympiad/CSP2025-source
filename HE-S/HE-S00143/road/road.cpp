#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>10){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
int n,m,k;
int a[15][10005];
struct bian{
	int u,v,w;
	int s;
};
bool cmp(bian x,bian y){
	return x.w<y.w;
}
bian P[2000005];
bian p[2000005];
int c[15];
int M;
long long ans;
int fa[1000025];
int fd(int x){
	while(fa[fa[x]]!=fa[x]){
		fa[x]=fa[fa[x]];
//		cout<<x<<" ffa "<<x<< " = "<<fa[fa[x]]<<endl;  
	}
	return fa[x];
}
void hb(int x,int y){
	x=fd(x);
	y=fd(y);
//	cout<<"fa "<<x<< " = "<<y<<endl;  
	fa[x]=y;
}
void TESTA(){
//	cout<<"@!";
	m=M;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			m++;
			p[m].u=i+n;
			p[m].v=j;
			p[m].w=a[i][j];
		}
	}
	sort(p+1,p+m+1,cmp);
	ans=0;
	for(int i=1;i<=m;i++){
		if(fd(p[i].u)==fd(p[i].v)){
			continue;
		}
		hb(p[i].u,p[i].v);
		ans+=p[i].w; 
	}
	write(ans);
	putchar('\n');
}
int f[15];
long long Ans=0x3f3f3f3f3f3f3f3f;
long long sc(){
	ans=0;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(f[i]==0){
			continue;
		}
		cnt++;
		ans+=c[i];
	}
	int bnt=0;
	if(ans>=Ans){
		return ans;
	}
	for(int i=1;i<=m;i++){
		if(fd(p[i].u)==fd(p[i].v)||f[p[i].s]==0){
			continue;
		}
		bnt++;
		hb(p[i].u,p[i].v);
		ans+=p[i].w; 
		if(ans>=Ans){
			return ans;
		}
	}
	if(bnt<cnt+n-1){
		return Ans;
	}
	return ans;
}

void dfs(int o){
	
	if(o>k){
//		for(int i=1;i<=k;i++){
//			cout<<f[i]<<" ";
//		}cout<<endl;
		Ans=min(Ans,sc());
		return ;
	}
	f[o]=0;
	dfs(o+1);
	f[o]=1;
	dfs(o+1);
}
int main(){
	freopen("road.in","r",stdin);
//	freopen("road4.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	M=read();
	m=M;
	k=read();
	for(int i=1;i<=m;i++){
		p[i].u=read();
		p[i].v=read();
		p[i].w=read();
		p[i].s=0;
	}
	int A=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]>0){
			A=0;
		}
		int minn=2;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			minn=min(minn,a[i][j]);
		} 
		if(minn>0){
			A=0;
		}
	}
	if(A){
		TESTA();
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			m++;
			p[m].u=i+n;
			p[m].v=j;
			p[m].w=a[i][j];
			p[m].s=i;
		}
	}
	f[0]=1;
	sort(p+1,p+m+1,cmp);
	dfs(1);
	write(Ans);
	return 0;
}
