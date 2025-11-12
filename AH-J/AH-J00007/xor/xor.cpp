#include <cstdio>
#include <unordered_map>
using namespace std;
int n,k,a,x,cnt,r,l;
unordered_map<int,int> mp;
int main(void) {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	mp[0]=1;
	for(int i=1;i<=n;++i) {
		scanf("%d",&a);
		x^=a;
		if(mp[x^k]>l) {
			++cnt;
			l=i;
		}
		mp[x]=i+1;
	}
	printf("%d",cnt);
	return 0;
}
