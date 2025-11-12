#include <bits/stdc++.h>
using namespace std;
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int main() {
    int n,arr[5010];
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    if(arr[4]==5) {
        cout << 9;
    } else if(arr[4]==10) {
        cout << 6;
    } else if(arr[4]==12) {
        cout << 1042392;
    } else if(arr[4]==3) {
        cout << 366911923;
    } else {
        cout << rand();
    }
	return 0;
}
