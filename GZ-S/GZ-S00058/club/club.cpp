//GZ-S00058  遵义市第四中学 刘林志远 
#include <cstdio>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

typedef long long ll;

ll fr() {
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

const int maxn=1e5+100;

struct node{
	int mx,cx;
	int mv,cv;
	bool operator< (const node &n) const&{
		return mv-cv>n.mv-n.cv;
	}
}a[maxn];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=fr();
	while(t--) {
		int ans=0;
		int n=fr();
		for(int i = 1; i <= n; i++) a[i].mv=a[i].cv=0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				int now=fr();
				if(now>a[i].mv) {
					a[i].cx=a[i].mx;
					a[i].cv=a[i].mv;
					a[i].mx=j;
					a[i].mv=now;
				}
				else if(now>a[i].cv) {
					a[i].cx=j;
					a[i].cv=now;
				}
			}
		}
		int cnt[]={0,0,0,0},aim=0;
		for(int i = 1; i <= n; i++) cnt[a[i].mx]++;
		for(int i = 1; i <= 3; i++) {if(cnt[i]>n/2) aim=i;}
		std::sort(a+1,a+1+n);
		int now=0;
		for(int i = 1; i <= n; i++) {
			if(a[i].mx==aim) {
				if(now<n/2) ans+=a[i].mv,now++;
				else ans+=a[i].cv;
			}
			else ans+=a[i].mv;
		}
		printf("%d\n",ans);
	}
	return 0;
}

