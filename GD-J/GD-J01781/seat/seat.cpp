#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long len;
long long r;
long long a[1000];
long long x,y;
bool cmp(long long c,long long d) {
	return c>d;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1; i<=len; i++) {
		cin>>a[i];

	}
	r=a[1];
	sort(a+1,a+len+1,cmp);
	for(int i=1; i<=len; i++) {

		if(a[i]==r) {
			r=i;
			break;
		}
	}
	x=r/n;
	y=r%n;
	if(y!=0) {
		x=x+1;
	}
	if(x/2==0) {
		cout<<x<<" "<<m-y;
	} else {
		cout<<x<<" "<<y;
	}
	return 0;
}
