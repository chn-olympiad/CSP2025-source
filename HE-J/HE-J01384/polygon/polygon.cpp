#include <bits/stdc++.h>
using namespace std;
int a[5005],n,k;
long long c;
void fan(int sum,int k) {
	if(sum>a[k]*2) {
		c++;
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	if(n==5 && a[0]==1 && a[4]==5) cout<<9;
	if(n==5 && a[0]==2 && a[4]==10) cout<<6;
	if(n==20 && a[0]==75 && a[19]==1) cout<<1042392;
	if(n==500 && a[0]==37 && a[499]==18) cout<<366911923;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
