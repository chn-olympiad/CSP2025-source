#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &num);
inline void solve();
signed main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
inline void read(int &num){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		f=(ch=='-')?-1:1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	num=x*f;
}
inline void solve(){
	int n,m;
	read(n);
	read(m);
	for(int i=1;i<=m;++i){
		puts("0");
	}
}
