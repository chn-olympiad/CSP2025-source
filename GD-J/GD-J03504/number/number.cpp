#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e6;
char s[MAXN+10];
int n,a[MAXN+10],ta[MAXN+10];
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
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1; i<=len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[++n]=s[i]-'0';
		}
	}
	msort(1,n);
	for(int i=1; i<=n; i++) {
		printf("%d",a[i]);
	}
	return 0;
}
