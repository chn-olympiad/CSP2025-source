#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define PLL pair<long long,long long>
#define VLL vector<long long>
const int N=114514;
ll n,m,v,T;
ll a[N][5],sum=0;
ll mx[N],id[N],t[N],s[N],d[N];
ll mx1[N],id1[N],t1[N],s1[N];
void init() {
	sum=0;
	memset(mx,0,sizeof mx);
	memset(mx1,0,sizeof mx1);
	memset(t,0,sizeof t);
	memset(s,0,sizeof s);
	memset(d,0,sizeof d);
	memset(b,0,sizeof b);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		init();
		scanf("%lld",&n);
		v=n/2;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=3; j++) {
				scanf("%lld",&a[i][j]);
				if(mx[i]<a[i][j]) {
					mx1[i]=mx[i];
					mx[i]=a[i][j];
					id[i]=j;
				} else if(a[i][j]>mx1[i]) mx1[i]=a[i][j];
			}
		for(int i=1; i<=n; i++) d[i]=mx[i]-mx1[i],sum+=mx[i];
		for(int i=1; i<=n; i++) t[id[i]]++;
		for(int i=1; i<=3; i++) if(t[i]>v) s[i]=t[i]-v;
		for(int i=1; i<=3; i++) {
			ll b[N],idx=0;
			for(int j=1; j<=n; j++) if(id[j]==i) b[++idx]=d[j];
			sort(b+1,b+1+idx);
			for(int j=1; j<=min(idx,s[i]); j++)sum-=b[j];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
