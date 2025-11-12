#include<bits/stdc++.h>
using namespace std;
int n,m,k,lie,han,x;
int a[1000];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int l=1,r=n*m;
	while(l<=r) {
		int mid=l+r>>1;
		if(a[mid]>=k) {
			x=mid;
			l=mid+1;
		}
		if(a[mid]<k) {
			r=mid-1;
		}
	}
	lie=x%n==0?(x/n):(x/n+1);
	int c=x%n==0?x:(x%n);
	han=lie%2==0?(n-c+1):c;
	cout<<lie<<" "<<han;
	return 0;
}

