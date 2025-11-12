//By Dream_Flynn(luogu name)
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int k=0;
	bool f=false;
	char c=getchar();
	while(!isdigit(c)){
		f=f||(c=='-');
		c=getchar();
	}
	while(isdigit(c)){
		k=(k<<3)+(k<<1)+(c^48);
		c=getchar();
	}
	return f?-k:k;
}
inline void write(int d,char end_ch='\n'){
	if(d<0){
		d=-d;
		putchar('-');
	}
	int stk[48],top=0;
	do{
		top++;
		stk[top]=d%10;
		d/=10;
	}while(d);
	for(int i=top;i;i--){
		putchar(stk[i]^48);
	}
	if(end_ch!='\0'){
		putchar(end_ch);
	}
}
const int N=1e4+5,M=1e6+5;
int n,m,k,idx,h[N],e[M<<1],ne[M<<1],w[M<<1],c[N],v2c[16][N];
inline void add(int a,int b,int c){
	idx++;
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx;
}
namespace PlanA{
	struct node{
		int x,y,z;
	}s[M];
	inline bool cmp(node d1,node d2){
		return d1.z<d2.z;
	}
	int fa[N];
	int get_fa(int x){
		if(fa[x]==x){
			return x;
		}
		return fa[x]=get_fa(fa[x]);
	}
	void main(){
		for(int i=1;i<=m;i++){
			int u=read(),v=read(),ww=read();
			s[i]={u,v,ww};
		}
		sort(s+1,s+m+1,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		int cnt=0,ans=0;
		for(int i=1;i<=m;i++){
			int xf=get_fa(s[i].x),yf=get_fa(s[i].y);
			if(xf==yf){
				continue;
			}
			fa[xf]=yf;
			cnt++;
			ans+=s[i].z;
			if(cnt==n-1){
				break;
			}
		}
		write(ans);
	}
}
namespace PlanB{
	struct node{
		int x,y,z;
	}s[2200050];
	inline bool cmp(node d1,node d2){
		return d1.z<d2.z;
	}
	int fa[N];
	bool v[N];
	int get_fa(int x){
		if(fa[x]==x){
			return x;
		}
		return fa[x]=get_fa(fa[x]);
	}
	void main(){
		int tot=0;
		for(int i=1;i<=n;i++){
			for(int j=h[i];j;j=ne[j]){
				tot++;
				s[tot]={i,e[j],w[j]};
			}
		}
		sort(s+1,s+tot+1,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		int cnt=0,ans=0;
		for(int i=1;i<=tot;i++){
			int xf=get_fa(s[i].x),yf=get_fa(s[i].y);
			if(xf==yf){
				continue;
			}
			fa[xf]=yf;
			if(s[i].x<=n&&v[s[i].x]==0){
				v[s[i].x]=1;
				cnt++;
			}
			if(s[i].y<=n&&v[s[i].y]==0){
				v[s[i].y]=1;
				cnt++;
			}
			ans+=s[i].z;
			if(cnt==n){
				break;
			}
		}
		write(ans);
	}
}

	
struct node{
	int x,y,z;
}s[M+N*11];
inline bool cmp(node d1,node d2){
	return d1.z<d2.z;
}
int stp,fa[N],ans,Ans=LLONG_MAX;
bool f[16],v[N];int get_fa(int x){
		if(fa[x]==x){
			return x;
		}
		return fa[x]=get_fa(fa[x]);
	}
void kskl(){
	ans=0;
	memset(v,0,sizeof v);
	sort(s+1,s+stp+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int cnt=0;
	for(int i=1;i<=stp;i++){
		if(s[i].x>n&&!f[s[i].x]){
			continue;
		}
		
		if(s[i].y>n&&!f[s[i].y]){
			continue;
		}
			int xf=get_fa(s[i].x),yf=get_fa(s[i].y);
			if(xf==yf){
				continue;
			}
			fa[xf]=yf;
			if(s[i].x<=n&&v[s[i].x]==0){
				v[s[i].x]=1;
				cnt++;
			}
			if(s[i].y<=n&&v[s[i].y]==0){
				v[s[i].y]=1;
				cnt++;
			}
			ans+=s[i].z;
			if(cnt==n){
				break;
			}
		}
}
void dfs(int d,int sum){
	if(d==n+1){
		kskl();
	Ans=min(ans+sum,Ans);
	}
	f[d]=0;
	dfs(d+1,sum);
	f[d]=1;
	dfs(d+1,sum+c[d]);
}
signed main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	if(k==0){
		PlanA::main();
		return 0;
	}
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),ww=read();
		stp++;
		s[stp]={u,v,ww};
	}
	bool allc0=true;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0){
			allc0=false;
		}
		for(int j=1;j<=n;j++){
			int x=read();
			v2c[i][j]=x;
			add(n+i,j,x);
			add(j,n+i,x);
			stp++;
			s[stp]={i,j,x};
		}
	}
	if(allc0){
		PlanB::main();
		return 0;
	}
	dfs(1,0);
	return 0;
}
//不是，T2是什么鬼东西啊？我已经假了114个做法了！qaq
//我打赌T2是MST，只是不知道接下来怎么搞。
//枚举每个村是否会被用到， 

//所以DEV里面写中文不会乱码吗？ 
 
//I think I had solved a similar problem on Luogu,but I forget it qaq.
//I think it's green.
//No,I had no time!
//I just need the ROAD to NOIP!
