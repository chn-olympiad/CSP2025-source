#include<bits/stdc++.h>
using namespace std;
int a[150];
int i1;
int c=1,r=1;
int zhuan=0;
bool cmp(int x,int y) {
	return y<x;
}
int main() {
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0; i<n*m; i++) {
		cin>>a[i];
		i1=i;
	}
	int R=a[0];
	sort(a,a+i1+1,cmp);
	if(n==1&&m==1) {
		cout<<"1"<<" "<<"1";
		return 0;
	}
	for(int i=0; i<n*m; i++) {
		if(a[i]==R)
			break;
		if(r!=n&&zhuan==0) {
			r++;
		} else if(r==n&&zhuan==0) {
			c++;
			zhuan=1;
		} else if(r!=1&&zhuan==1) {
			r--;
		} else if(r==1&&zhuan==1) {
			c++;
			zhuan=0;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
