#include <bits/stdc++.h>
using namespace std;
int c,r;
int a[101];
int l[10][10];
bool cmp1(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	int p=c*r;
	for(int i=1; i<=p; i++) {
		cin>>a[i];
	}
	int ansb=a[1];
	sort(a+1,a+p+1,cmp1);
	int pao=1,answei=0;
	for(int i=1; i<=p; i++) {
		if(a[i]==ansb) answei=i;
	}
	int l=1;
	for(int i=1; i<=c; i++) {
		if(i%2==1) {
			for(int j=1; j<=r; j++) {
				if(l==answei) {
					cout<<i<<" "<<j;
//					cout<<" "<<l<<" "<<answei;
					return 0;
				}
				l++;
			}
		} else if(i%2==0) {
//			cout<<endl;
			for(int j=r; j>=1; j--) {
				if(l==answei) {
					cout<<i<<" "<<j;
//					cout<<" "<<l<<" "<<answei;
					return 0;
				}
				l++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 3
96 100 99 98 97 91 77 89 90 70 66 61
*/