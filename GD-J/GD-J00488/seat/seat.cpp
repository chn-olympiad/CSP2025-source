#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n, m;
int f[200];

bool cmp(int a,int b) {
	return a>b;
}

int main() {
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int nm=n*m;
	for(int i=1;i<=nm;i++) {
		scanf("%d",&f[i]);
	}
	int xr=f[1];
	sort(f+1,f+1+nm,cmp);
	int tot=0;
	for(int i=1;i<=m;i++) {
		if(i%2==1) {
			for(int j=1;j<=n;j++) {
				if(f[++tot]==xr) {
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		if(i%2==0) {
			for(int j=n;j>=1;j--) {
				if(f[++tot]==xr) {
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
} 
