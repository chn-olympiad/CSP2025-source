#include<bits/stdc++.h>
using namespace std;
constexpr int SIZE = 1<<21;
char in[SIZE],out[SIZE],*p1=in,*p2=in,*p3=out;
#define getc() (p1==p2&&(p2=(p1=in)+fread(in,1,SIZE,stdin),p1==p2)?EOF:*p1++)
#define flush() (fwrite(out,1,p3-out,stdout),p3=out)
#define putc(ch) (p3==out?(flush()):0,*p3++=ch)
class Flush{
	public:~Flush(){
		flush();
	}
}_;
template<class T>
void read(T &x){
	x=0;char c = getc();int f=1;
	while(c<'0' || c>'9'){
		if(c=='-'){
			f=-1;
		}
		c = getc();
	}
	while(c>='0' && c<='9'){
		x = (x<<3)+(x<<1)+(c^48);
		c = getc();
	}
	x*=f;
}
template<typename T,typename ...Args>
void read(T &x,Args&... x1){
	read(x),read(x1...);
}
template<typename type>
void write(bool f,type x){
	short static sta[30];short top=0;
	if(x<0) putc('-'),x=-x;
	while(x || top==0) sta[++top] = x%10,x/=10;
	while(top--) putc(char(sta[top+1]^48));
	(f)?putc(' '):putc('\n');
}
template<typename type,typename ...Args>
void write(bool f,type x,Args... x1){
	write(f,x),write(f,x1...);
}
namespace my_space{
	using ll = long long;
	constexpr int N = 1e4+50,M = 1e6+50;
	ll sum,ans=1e18,c[11];
	int f[N],n,m,tot,tag[11],k;
	struct tt{
		int a,b,ty;
		ll v;
		int friend operator<(tt a,tt b){
			return a.v<b.v;
		}
	}e[N*12+M];
	int find(int x){
		if(f[x]==x) return x;
		return f[x] = find(f[x]); 
	}
	void solve(){
		sum=0;
		for(int i=1;i<=n+k;i++){
			f[i] = i;
		}
		for(int i=1;i<=tot;i++){
			if(e[i].ty==1 || (e[i].a>n && tag[e[i].a-n])){
				int a = find(e[i].a),b = find(e[i].b);
				if(a!=b){
					f[a] = f[b];
					sum+=e[i].v;
				} 
			}
		}
	}
	void dfs(int pos,ll val){
		if(pos==k+1){
			solve();
			ans = min(ans,sum+val);
			return;
		} 
		if(val>ans) return;
		dfs(pos+1,val);
		tag[pos] = 1;
		dfs(pos+1,val+c[pos]);
		tag[pos]=0;
	} 
	int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		read(n,m,k);
		int fl=1;
		for(int i=1;i<=m;i++){
			tot++;
			read(e[tot].a,e[tot].b,e[tot].v);
			e[i].ty = 1;
		}
		for(int i=1;i<=k;i++){
			read(c[i]);
			if(c[i]!=0) fl=0;
			for(int j=1;j<=n;j++){
				tot++;
				read(e[tot].v);
				e[tot].a = i+n,e[tot].b=j;
			}
		}
		sort(e+1,e+1+tot);
		if(fl){
			for(int i=1;i<=k;i++){
				tag[i] =1;
			} 
			solve();
			write(0,sum);
		}
		else{
			dfs(1,0);
			write(0,ans);
		}
		return 0;
	}
}
int main(){
	return my_space::main();
}

