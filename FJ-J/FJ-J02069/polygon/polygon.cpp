#include<bits/stdc++.h>
#include<set>
using namespace std;
bool a[5005];
long long c[5005];
int n,jj,tot = 0,pu = 1;
void print() {
	for(int i = 1; i<=n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}
void dfs(int t,int no = 1) {
	
	if(t == 0 ) {
		long long e = INT_MIN,ce = 0,totot = 0;
		 
		print();
		if(totot == 5) return;
		for(int i = 1; i<=n; i++) {
			if(a[i] == 1) {
				e = max(e,c[i]);
				ce += c[i];
//				printf("%lld %lld\n",e,ce);
				
			}
		}
		if(2*e < (ce)) {
			tot++;
//			printf("tot = %d\n",tot);
		}
		if(jj == n) exit(0);
	} else {
		
		for(int i = no; i<=n; i++) {
			if(a[i] != 1) {
				a[i] = 1;
				dfs(t-1,no);
				a[i] = 0;
			}
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i<=n; i++) {
		scanf("%lld",&c[i]);
	}
	sort(c+1,c+n+1);
	jj = 3;
	for(int i = 3; i<=n; i++) {
		dfs(i);
		jj++;
	}
	printf("%d\n",tot);
	return 0;
}
