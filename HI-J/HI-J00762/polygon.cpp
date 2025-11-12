#include<bits/stdc++.h>
using namespace std;

const int MAXN=5010;

int n,ji=0,amax=-1;
int a[MAXN],ans=0;
int mod=998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		amax=max(amax,a[i]);
	}
	if(n<=3) {
		for(int i=1; i<=n; i++) {
			amax=max(amax,a[i]);
			ji=a[i]+ji;
		}
		if(ji>amax*2) printf("1");
		else printf("0");
	} else {
		if(amax==1) {
			ji=1;
			int ji1=2;
			int j[510][510];
			memset(j,0,sizeof(j));
			for(int i=1; i<=n; i++) {
				j[i][1]=ji;
				ji=ji+ji1;
				ji1++;
				for(int k=2; k<=i; k++) {
					j[i][k]=j[i-1][k]+j[i-1][k-1];
				}
			}
			for(int i=1; i<=n; i++) {
				for(int k=1; k<=i; k++) {
				//	printf("j[%d][%d]=%d\n",i,k,j[i][k]);
					ans+=j[i][k];
				}
			}
			printf("%d",ans);
		}
	}
	return 0;
}
