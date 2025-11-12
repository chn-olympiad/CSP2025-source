#include<bits/stdc++.h>
#define N (int)(1e3+5)
using namespace std;
int a[N],G[N][N];
inline void read(int &num);
inline void solve();
inline bool cmp(const int &A,const int &B);
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
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
	for(int i=1;i<=n*m;++i){
		read(a[i]);
	}
	int R=a[1],ct=0;
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;++j){
		if(j&1){
			for(int i=1;i<=n;++i){
				++ct;
				if(a[ct]==R){
					printf("%d %d",j,i);
				}
			}
		}else{
			for(int i=n;i>=1;--i){
				++ct;
				if(a[ct]==R){
					printf("%d %d",j,i);
				}
			}
		}
	}
}
inline bool cmp(const int &A,const int &B){
	return A>B;
}
