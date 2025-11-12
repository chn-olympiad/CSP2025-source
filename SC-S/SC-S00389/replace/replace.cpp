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
const int N=2e5+5;
int n,q,cnt[N<<1][2];
string s[N][2],t[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n,q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(auto j:s[i][0]){
			if(j=='b'){
				break;
			}
			cnt[i][0]++;
		}
		for(auto j:s[i][1]){
			if(j=='b'){
				break;
			}
			cnt[i][1]++;
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t[i][0]>>t[i][1];
		for(auto j:t[i][0]){
			if(j=='b'){
				break;
			}
			cnt[i+n][0]++;
		}
		for(auto j:t[i][1]){
			if(j=='b'){
				break;
			}
			cnt[i+n][1]++;
		}
		for(int j=1;j<=n;j++){
			if(t[i][0].size()<s[j][0].size())continue;
			if(cnt[j][0]>cnt[i+n][0])continue;
			if((s[j][0].size()-cnt[j][0]-1)>(t[i][0].size()-cnt[i+n][0]-1))continue;
			if((cnt[j][0]-cnt[j][1])!=(cnt[i+n][0]-cnt[i+n][1]))continue;
			ans++;
		}
		print(ans);
	}
	return 0;
}