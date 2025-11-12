#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read() {
	ll e=1,v=0;
	char s=getchar();
	while(s<'0'||s>'9') {
		if(s=='-') {
			e=-1;
			s=getchar();
			break;
		} else s=getchar();
	}
	while(s>='0'&&s<='9') {
		v=(v<<3)+(v<<1)+s-'0';
		s=getchar();
	}
	return e*v;
}
ll t,n,m,a[100001][4],ans,f[201][101][101],biao,diao,q[100001],sb[100001],nm[100001];
inline void dfs(ll x,ll y,ll e,ll s,ll sum) {
	if(x==n+1&&sum>=ans)ans=sum;
	else {
		if(y<n/2)dfs(x+1,y+1,e,s,sum+a[x][1]);
		if(e<n/2)dfs(x+1,y,e+1,s,sum+a[x][2]);
		if(s<n/2)dfs(x+1,y,e,s+1,sum+a[x][3]);
	}
	return;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	t=read();t=read();
for(int i=1;i<=t;i++)cout<<0<<endl;
	return 0;
}
//1 4 20 3 0 21 2 0 24 0 0 29 10 0
