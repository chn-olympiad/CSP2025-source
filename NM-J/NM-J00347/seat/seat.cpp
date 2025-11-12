#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n*m];
	for (int i = 0;i<n*m;i++)cin>>arr[i];
	int Q = arr[0];
	sort(arr,arr+n*m);
	int L = 0,R = n*m-1;
	while (L<=R) {
		int mid = L+((R-L)>>1);
		if (arr[mid]==Q) {
			L = mid;
			break;
		}
		if (arr[mid]<Q)L = mid+1;
		else R = mid-1;
	}
	int x = 1,y = 1,h = -1;
	for (int i = n*m-1;i>L;i--) {
		y-=h;
		if (y==0||y>m)x++,h*=-1,y-=h;
	}
	cout<<x<<' '<<y;
}
