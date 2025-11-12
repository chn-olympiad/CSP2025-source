#include<cstdio>
#include<map>
using namespace std;
const int MAXN=5e5;
int n,k,a[MAXN+10];
map<int,bool>mp;
int main(void) {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		mp[0]=true;
		int xs=a[i],poi=i+1;
		while(!mp[xs^k]&&poi<=n) {
			mp[xs]=true;
			xs^=a[poi];
			++poi;
		}
		if(mp[xs^k]) {
			++ans;
		}
		i=poi-1;
		mp.clear();
	}
	printf("%d",ans);
	return 0;
}
