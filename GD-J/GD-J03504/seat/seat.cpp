#include<cstdio>
using namespace std;
const int MAXN=10;
int n,m;
int a1,a[MAXN*MAXN+10];
int ta[MAXN*MAXN+10];
void msort(int l,int r) {
	if(l>=r) {
		return;
	}
	int mid=(l+r)>>1;
	msort(l,mid);
	msort(mid+1,r);
	int p1=l,p2=mid+1;
	for(int i=l; i<=r; i++) {
		if((p2>r)||((p1<=mid)&&(a[p1]>a[p2]))) {
			ta[i]=a[p1];
			++p1;
		} else {
			ta[i]=a[p2];
			++p2;
		}
	}
	for(int i=l; i<=r; i++) {
		a[i]=ta[i];
	}
	return;
}
int main(void) {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++) {
		scanf("%d",&a[i]);
	}
	a1=a[1];
	msort(1,n*m);
	int poi=1,ans1=0,ans2=0;
	bool f=false;
	for(int j=1; j<=m; j++) {
		if(j&1) {
			for(int i=1; i<=n; i++) {
				if(a[poi]==a1) {
					ans1=j;
					ans2=i;
					f=true;
					break;
				}
				++poi;
			}
		} else {
			for(int i=n; i>=1; i--) {
				if(a[poi]==a1) {
					ans1=j;
					ans2=i;
					f=true;
					break;
				}
				++poi;
			}
		}
		if(f) {
			break;
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
