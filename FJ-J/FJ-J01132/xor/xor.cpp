#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 20) + 11;

int n,k,ans;
int a[500011],s[N];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		a[i] ^= a[i - 1];
	}
	memset(s,-1,sizeof s);
	s[0] = 0;
	int last = 0;
	for(int i=1;i<=n;i++) {
		int w = k ^ a[i];
		int st = s[w] + 1;
		if (s[w] != -1 && st > last) {
			ans++;
			last = i;
		}
		s[a[i]] = i;
	}
	printf("%d",ans);
	return 0;
} 
