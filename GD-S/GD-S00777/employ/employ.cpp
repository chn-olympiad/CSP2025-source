#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Maxn=2e5+10,p=998244353;

int n,m,c[Maxn];
string str;
ll ans=1;

int main() {
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	cin>>str;
//	if(n==m) {
//		cout<<0;
//		return 0;
//	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
	}
	for(int i=n;i>=1;i--) {
		ans*=(1ll*i);
		ans%=p;
//		cout<<ans<<endl;
//		if(ans==161088479) {
//			cout<<i<<endl;
//		}
	}
	/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

35305197
161088479
	*/
	printf("%lld\n",ans);
	return 0;
}
