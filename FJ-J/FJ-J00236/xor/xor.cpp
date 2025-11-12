#include <iostream>
#include <cstdio>
#include <map>
#define ll long long
#define N 500005
#define PII pair<ll, ll>
#define INF (ll)1e9

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return res*f;
}
ll n, k, a[N], sum, l[N], ans, pos=-1;
map<ll, ll> s;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n=rd(), k=rd();
	for(int i=1; i<=n; i++) a[i]=rd();
	s[0]=0; 
	for(int i=1; i<=n; i++){
		sum^=a[i];
		if(s.count(sum^k)) l[i]=s[sum^k]+1;
		else l[i]=INF;
		s[sum]=i;
	}
	for(int i=1; i<=n; i++){
		if(l[i]==INF) continue;
		else if(l[i]>pos) ans++, pos=i;
	}
	printf("%lld\n", ans);

	return 0;
}
/*
4 2
2 1 0 3
*/

