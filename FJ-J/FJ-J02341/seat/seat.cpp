#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a[1];
    int t=a[1];
    int p=n*m;
	for(int i=2;i<=p;i++) {
    	cin>>a[i];
	}
	int c=1;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=p;i++) {
		if(t==a[i]) {
			break;
	    } else {
	    	c++;
		}
	}
	int lie=0,hang=0;
	while(c<=0) {
		if(c-n>=0) {
			c-=n;
			lie++;
		}
		if(c-n<0) {
			if(lie%2==0) {
				hang=c;
			}
			if(lie%2==1) {
				hang=n-c+1;
			}
		}
		if(n==0) {
			hang=4;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
