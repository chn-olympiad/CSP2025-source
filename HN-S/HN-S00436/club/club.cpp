#include<bits/stdc++.h>
using namespace std;
#define def(X) constexpr int X=
#define LF putchar('\n')
#define SP putchar(' ')
#define int long long
template<typename T>
inline void read(T& x){
	x=0;int f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=~f+1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x*=f;
}
template<typename T,typename... Args>
inline void read(T& x,Args&... args){
	read(x);
	read(args...);
}
template<typename T>
inline void write(T x){
	static int buf[40],top=0;
	if(x<0){x=-x;putchar('-');}
	while(x){buf[++top]=x%10,x/=10;}
	if(!top)buf[++top]=0;
	while(top)putchar(buf[top--]^48);
}
template<typename T,typename... Args>
inline void write(T x,Args... args){
	write(x);
	SP;
	write(args...);
}
def(N) 1e5+10;
int T,n;
struct node{int v,p;}a[N][4];
int d[N],c[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	read(T);
	while(T--){
		read(n);
		c[1]=c[2]=c[3]=0;
		int ans=0;
		for(i=1;i<=n;++i){
			d[i]=0;
			for(j=1;j<=3;++j){
				read(a[i][j].v);
				a[i][j].p=j;
			}
			sort(a[i]+1,a[i]+4,[](node x,node y){return x.v>y.v;});
			++c[a[i][1].p];
			ans+=a[i][1].v;
			d[i]=a[i][1].v-a[i][2].v;
		}
		int t=max_element(c+1,c+4)-c;
		if(c[t]<=n/2){
			write(ans),LF;
			continue;
		}
		vector<int> res;
		for(i=1;i<=n;++i){
			if(a[i][1].p==t)res.push_back(d[i]);
		}
		sort(res.begin(),res.end());
		for(auto it:res){
			if(c[t]<=n/2) break;
			ans-=it;
			c[t]--;
		}
		write(ans),LF;
	} 
	return 0;
}
