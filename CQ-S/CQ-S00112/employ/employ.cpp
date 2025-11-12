#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
const int mod =  998244353; 
int n,m;
char s[N];
int a[N];
ll ans = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s + 1);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++) ans = (ans * i) % mod;
	printf("%lld",ans);
	return 0;
}
