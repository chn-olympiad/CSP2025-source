#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const ll p=998244353;
int n,m,cnt;
int c[N],fac[N];
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) if(s[i]=='1') cnt++;
	if(cnt<m) return puts("0"),0;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%p;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n);
	if(n==m) {printf("%lld\n",fac[n]);return 0;}
	int res=1;
	while(c[res]==0&&res<=n) res++;
	return 0;
}

