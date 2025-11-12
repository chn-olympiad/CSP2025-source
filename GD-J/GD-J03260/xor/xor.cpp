#include <cstdio>
#include <set>
using namespace std;

set<long long> s;
long long a[523232],sum[523232];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n; long long k;
	scanf("%d%lld",&n,&k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",a+i);
		sum[i] = sum[i-1]^a[i];
	}
	int ans = 0; s.insert(0ll);
	for (int i = 1; i <= n; i++) {
		if (s.count(sum[i]^k)) {
			ans++; s.clear();
		}
		s.insert(sum[i]);
	}
	printf("%d",ans);
	return 0;
} 
// 看着一眼假，但是大洋理都过了，无法哈克。算了白兰。 
// freopen("or.in","w",stderr);
