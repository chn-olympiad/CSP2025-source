#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

char s[N];
int cnt,k[N];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s + 1);
	int n = strlen(s + 1);
	for(int i = 1;i <= n;i++)
		if(s[i] >= '0' && s[i] <= '9')
			k[++cnt] = s[i] - '0';
	sort(k + 1,k + 1 + cnt);
	for(int i = cnt;i >= 1;i--)
		printf("%lld",k[i]);
	return 0;
}