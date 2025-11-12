#include <bits/stdc++.h>
using namespace std;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout)
bool cmp(int a,int b) {
	return a>b;
}
int main() {
    int n,m;
    int x;
    cin >> n >> m;
    int arr[101];
    int b;
    for(int i=0;i<n*m;i++) {
        cin >> arr[i];
    }
    b=arr[0];
	sort(arr,arr+n*m,cmp);
	for(int i=0;i<n*m;i++) {
        if(arr[i]==b) {
            x=i+1;
        }
	}
	if(((x/n+1)%2)==0) {
        cout << ceil(x/m) << ' ' << n-(x%n);
	} else {
        cout << ceil(x/m)+1 << ' ' << x%n;
	}
	return 0;
}
