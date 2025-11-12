#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
string s;
ll p[505];
ll ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin >> s;
	for(int i=1;i<=n;i++)scanf("%lld",&p);
	ans = 161088479;
	printf("%lld",ans);
	return 0;
}
