#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)  cin >> a[i];
	int x=a[1],sum=0;
	sort(a,a+n*m+1);
	for(int i = n*m;i >= 1;i--) {
		if(a[i] == x) {
			sum=n*m-i+1;
			break;
		}
	}
	int ansm;
	if(sum % n == 0) ansm=sum/n;
	else  ansm=sum/n+1;
	int ansn=0;
	int y=sum%n;
	if(ansm % 2 == 0) {
		if(y == 0) ansn=1;
		else ansn=n-y+1;
	}
	else {
		if(y == 0)  ansn=n;
		else  ansn=y;
	}
	cout << ansm << " " << ansn;
	return 0;
}
