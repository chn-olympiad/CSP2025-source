#include<bits/stdc++.h>
#define int long long
namespace FastIO{
	template<typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);x*=f;
	}
	template<typename T,typename...Args>
	inline void read(T &x,Args&...args){
		read(x);
		read(args...);
	}
	template<typename T>void print(T x){
		if(x<0)x=-x,putchar('-');
		if(x>9)print(x/10);
		putchar((x%10)^48);
	}
}
using namespace FastIO;
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,c[N],ans=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n,m);
	cin>>s;
	for(int i=1;i<=n;i++){
		read(c[i]);
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	print(ans);
	return 0;
}