#include<bits/stdc++.h>
using namespace std;
int t;
bool z1[200005],z2[200005],z3[200005];
bool cmp(int a,int b) {
	return b<a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		int f1[5][200005],f2[5][200005],f3[5][200005],n,a[5][200005],sum1=0,sum2=0,sum3=0,a1[500005],b1[500005],c1[500005],a2[200005],b2[200005],c2[200005];
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d %d %d",&a[1][i],&a[2][i],&a[3][i]);
			f1[1][i]=a[1][i];
			f2[1][i]=a[1][i];
			f3[1][i]=a[1][i];
			f1[2][i]=a[2][i];
			f2[2][i]=a[2][i];
			f3[2][i]=a[2][i];
			f1[3][i]=a[3][i];
			f2[3][i]=a[3][i];
			f3[3][i]=a[3][i];
			a2[i]=a[1][i];
			b2[i]=a[2][i];
			c2[i]=a[3][i];
		}
		sort(a2+1,a2+1+n,cmp);
		sort(b2+1,b2+1+n,cmp);
		sort(c2+1,c2+1+n,cmp);
		for(int i=1; i<=n/2; i++) {
			if(a2[i]==a[1][i])z1[i]=1,f1[2][i]=-1,f1[3][i]=-1;
			if(b2[i]==a[2][i])z2[i]=1,f2[1][i]=-1,f2[3][i]=-1;
			if(c2[i]==a[3][i])z3[i]=1,f3[1][i]=-1,f3[2][i]=-1;
		}
		for(int i=1; i<=n; i++) {
			a1[i]=f1[2][i];
			a1[i+n]=f1[3][i];
			b1[i]=f2[1][i];
			b1[i+n]=f2[3][i];
			c1[i]=f3[1][i];
			c1[i+n]=f3[2][i];
		}
		sort(a1+1,a1+1+2*n,cmp);
		sort(b1+1,b1+1+2*n,cmp);
		sort(c1+1,c1+1+2*n,cmp);
		for(int i=1; i<=n/2; i++) {
			sum1+=a2[i];
			sum2+=b2[i];
			sum3+=c2[i];
			sum1+=a1[i];
			sum2+=b1[i];
			sum3+=c1[i];
		}
		printf("%d\n",max(sum1,max(sum2,sum3)));
	}
	return 0;
}