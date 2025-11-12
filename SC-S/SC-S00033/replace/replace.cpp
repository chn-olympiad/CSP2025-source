#include<bits/stdc++.h>
#include<bits/extc++.h>
inline int read(){
	int x=0,f=1; char ch; ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isalnum(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int maxn=5e5+10;
inline int min(int x,int y){
	if(x<y) return x;
	return y;
}
int n,q,sum,ok;
std::string S1[maxn],S2[maxn],S,T;
inline void check(int id){
	int len=min(S.size(),T.size())-1,siz=S1[id].size()-1,siz2=S2[id].size()-1;
	for(int i=0;i<=len;++i){
		if(S[i]==S1[id][0]){
			if(len-i<siz) return ;
			for(int j=0;j<=siz;++j){
				if(S[i+j]!=S1[id][j]) break;
				if(j==siz){
					if(S.size()+siz2-siz!=T.size()) break;
					if(i+siz2+ok<(int)T.size()-1) break;
					for(int k=0;k<=siz2;++k){
						if(T[i+k]!=S2[id][k]) break;
						if(k==siz2) sum++;
					}
				}
			}
		}
		if(S[i]!=T[i]) return ;
	}
}
inline void solve(){
	std::cin>>S>>T;
	sum=0; ok=0;
	for(int i=1;i<=min(S.size(),T.size());++i){
		if(S[S.size()-i]!=T[T.size()-i]) break;
		ok++;
	}
	for(int i=1;i<=n;++i) check(i);
	write(sum); puts("");
}
inline void work(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	n=read(); q=read();
	for(int i=1;i<=n;++i) std::cin>>S1[i]>>S2[i];
	while(q--) solve();
}
signed main(){work();return 0;}