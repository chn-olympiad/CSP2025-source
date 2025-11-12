#include <bits/stdc++.h>
#define ll long long
#define pii array<ll,2>
using namespace std;
ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+(ch-'0');
		ch=getchar();
	}
	return s*f;
}
ll ans,t,n,d[3][100010],c[100010][3],p[3],s[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read(),ans=0;
		for(ll x:{0,1,2}) p[x]=0;
		for(ll i=1;i<=n;i++) for(ll x:{0,1,2}) c[i][x]=read();
		for(ll i=1;i<=n;i++){
			for(ll x:{0,1,2}) s[x]=x;
			sort(s,s+3,[&](ll x,ll y){return c[i][x]>c[i][y];});
			d[s[0]][++p[s[0]]]=c[i][s[0]]-c[i][s[1]];
			ans+=c[i][s[0]];
		}
		for(ll x:{0,1,2})
			if(p[x]>n/2){
				sort(d[x]+1,d[x]+1+p[x]);
				for(ll i=1;i<=p[x]-n/2;i++) ans-=d[x][i];
			}
		printf("%lld\n",ans);
	}
	return 0;
}
//g++ club.cpp -o club -std=c++14 -O2 -Wall -Wextra -fno-ms-extensions