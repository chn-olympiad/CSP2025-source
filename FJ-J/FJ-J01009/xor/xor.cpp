#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005],b[1005],cnt;
pair <int,int> c[1000005];
bool cmp(pair <int,int> p1,pair <int,int> p2) {
	return (p1.second < p2.second) || ((p1.second == p2.second) && (p1.first > p2.first));
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,temp = 0,ans = 0;
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j+i-1 <= n;j++) {
			b[j] ^= a[j+i-1];
			if (b[j] == k) {
				c[++cnt] = make_pair(j,j+i-1);
			}
		}
	}
	sort(c+1,c+cnt+1,cmp);
	for (int i = 1;i <= cnt;i++) {
		if (c[i].first > temp) {
			temp = c[i].second;
			ans++;
		}
	}
	printf("%d",ans); 
	return 0;
}
