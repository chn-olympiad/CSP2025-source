#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template <typename T>
inline void read(T&x){
	int w = 0; x = 0;
	char ch = getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') w = 1;
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		x = x*10+(ch^48);
		ch = getchar();
	}
	if(w) x = -x;
}
template <typename T,typename...Args>
inline void read(T&t,Args&...args){
	read(t); read(args...);
}
template <typename T>
inline T Max(T x,T y){ return (x > y ? x : y); }
template <typename T>
inline T Min(T x,T y){ return (x < y ? x : y); }
template <typename T>
inline T Abs(T x){ return (x < 0 ? -x : x); }
const ull base = 2333;
char s1[2100],s2[2100];
int n,m;
ull mul[2100],h1[2100],h2[2100];
inline ull hs(ull s[],int l,int r){
	if(l>r) return 0;
	return s[r]-s[l-1]*mul[r-l+1];
}
map <ull,int> mp;
int cnt;
set <ull> se[1010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
		
	read(n,m);
	mul[0] = 1;
	for(int i=1;i<=2000;++i) mul[i] = mul[i-1]*base;
	for(int i=1;i<=n;++i){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		ull ht1 = 0,ht2 = 0;
		int len = strlen(s1+1);
		for(int j=1;j<=len;++j){
			ht1 = ht1*base+s1[j];
			ht2 = ht2*base+s2[j];
		}
		if(!mp[ht1]) mp[ht1] = ++cnt;
		se[mp[ht1]].insert(ht2);
	}
	for(int i=1;i<=m;++i){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		if(strlen(s1+1)!=strlen(s2+1)){
			puts("0");
		}
		else{
			int res= 0 ;
			int len = strlen(s1+1);
			for(int l=1;l<=len;++l) h2[l] = h2[l]*base+s2[l],h1[l] = h1[l-1]*base+s1[l];
			for(int l=1;l<=len;++l){
				for(int r=l;r<=len;++r){
					if(mp.find(hs(h1,l,r))==mp.end()) continue;
					else if(hs(h1,1,l-1)!=hs(h2,1,l-1) || hs(h1,r+1,len)!=hs(h2,r+1,len)) continue;
					else{
						ull t2 = hs(h2,l,r);
						ull t1 = hs(h1,l,r);
						if(se[mp[t1]].find(t2)!=se[mp[t1]].end()) ++res;
 					}
				}
			}
			printf("%d\n",res);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
