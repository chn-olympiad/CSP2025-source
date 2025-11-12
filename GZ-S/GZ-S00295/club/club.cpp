//GZ-S00295 遵义市第五中学 江信杰
#include <bits/stdc++.h>
using namespace std;
int t,n,sum=0,mx=0,m2x=0,e,a[100005],b[100005];
int s1=0,s2=0,s3=0;
int d[200005][4];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		scanf("%d",&n);
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=3; k++) {
				scanf("%d",&d[j][k]);
			}
		}
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=3; k++) {
				if(mx<d[j][k]) {
					mx=d[j][k];
					b[j]=k;
				}
			}
			if(b[j]==1) {
				s1++;
			} else if(b[j]==2) {
				s2++;
			} else if(b[j]=3) {
				s3++;
			}
			a[j]=mx;
			mx=0;
		}
		if(e<s1){
			b[n]={1};
			e=s1;
		}
		if(e<s2){
			b[n]={2};
			e=s2;
		}
		if(e<s3){
			b[n]={3};
			e=s3;
		}
		sort(a,a+n);
		if(e>n/2) {
			for(int j=1; j<=n/2; j++) {
				for(int k=1; k<=3; k++) {
					if(m2x<d[j][k]&&k!=b[j]) {
						m2x=d[j][k];
						b[j]=k;
					}
				}
				a[j]=m2x;
			}
		}
		for(int j=1; j<=n; j++) {
			sum+=a[j];
		}
		printf("%d\n",sum);
		sum=0;
		e=0;
		s1=0;
		s2=0;
		s3=0;
		b[n]={0};
	}
	return 0;
}


