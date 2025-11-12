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
	int t,n,ans;
	constexpr int N=  1e5+50;
	struct tt{
		int a,b,c,v;
	}e[N];
	int cmp1(tt a,tt b){
		return a.a>b.a;
	}
	int cmp2(tt a,tt b){
		return max(a.a,a.b)>max(b.a,b.b);
	}
	void dfs(int pos,int a,int b,int c,int sum){
		if(pos==n+1){
			ans = max(ans,sum);
			return;
		}
		if(a<n/2){
			dfs(pos+1,a+1,b,c,sum+e[pos].a); 
		}
		if(b<n/2){
			dfs(pos+1,a,b+1,c,sum+e[pos].b); 
		}
		if(c<n/2){
			dfs(pos+1,a,b,c+1,sum+e[pos].c); 
		}
	}
	int main(){
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		read(t);
		while(t--){
			ans=0;
			read(n);
			int a=0,b=0,c=0;
			int spa=1,spb=1;
			for(int i=1;i<=n;i++){
				read(e[i].a,e[i].b,e[i].c);
				if(!(e[i].a==0 || e[i].b==0 || e[i].c==0)){
					spa=0;
				}
				if(!((e[i].a==0 && e[i].b==0)||(e[i].c==0 && e[i].b==0)||(e[i].a==0 && e[i].c==0))){
					spb=0;
				}
			}
			if(n<15){
				dfs(0,0,0,0,0); 
			}
			else if(spa||spb){
				for(int i=1;i<=n;i++){
					ans+=e[i].b;
					e[i].a-=e[i].b;
				}
				sort(e+1,e+1+n,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=e[i].a;
				}				
			}else{
				int tag[N];
				memset(tag,0,sizeof tag);
				int ct =n,at=0,bt=0;
				for(int i=1;i<=n;i++){
					ans+=e[i].c;
					e[i].a-=e[i].c;
					e[i].b-=e[i].c;
					e[i].c-=e[i].c;
				}
				sort(e+1,e+1+n,cmp2);
				int i=n;
				while(at<n/2 && max(e[i].a,e[i].b)>=0 && i>=1){
					if(e[i].a>e[i].b){
						ans+=e[i].a;
						at++; 
						tag[i] = 1;
					}
					else if(e[i].a==e[i].b){
						ans+=e[i].a;
						a++;
						tag[i]=1;
					}
					i--;
				} 
				int temp = a-(n-at);
				i=n;
				while(temp+bt<n/2 && max(e[i].a,e[i].b)>=0 && i>=1){
					if(tag[i]) continue;
					if(e[i].a<e[i].b){
						ans+=e[i].b;
						bt++; 
						tag[i] = 1;
					}
					else if(e[i].a==e[i].b){
						ans+=e[i].a;
						tag[i]=1;
					}
					i--;
				}
				if(c-(a+at+bt)>n/2){
					int cnt = c-(a+at+bt);
					while(i>=1 && cnt--){
						ans+=max(e[i].a,e[i].b);
					}
				}
			}
			write(0,ans);
		}
		return 0;
	}
}
int main(){
	return my_space::main();
}
