#include<bits/stdc++.h>
using namespace std;
#define N 510
inline void read(int& x){
	x=0;
	char ch=getchar();
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-')f=~f+1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x=f*x;
}
int n,m,pre[N];
int c[N],s[N];
int vis[N];
long long ans;
const int mod=998244353;
void dfs(int day,int given){
//	cout<<day<<" "<<given<<endl;
	if(day==n+1){
		if(n-given>=m) ans=(ans+1)%mod;
		return ;
	}
	if(day-given-1+pre[n]-pre[day-1]<m) return ;
//	int pos=upper_bound(c+1,c+1+n,given)-c;
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
//		if(given>=c[i]) continue;
		vis[i]=1;
		dfs(day+1,given+(s[day]==0||given>=c[i]));
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j;
//	read(n);read(m);
cin>>n>>m;
	for(i=1;i<=n;++i){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
		pre[i]=pre[i-1]+s[i];
	}
	for(i=1;i<=n;++i){
//		read(c[i]);
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/

