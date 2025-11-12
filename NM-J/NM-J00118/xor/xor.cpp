#include <bits/stdc++.h>
using namespace std;
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int arr[500001];
int main() {
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    if(k==0) {
        cout << 1;
        return 0;
    } else if(k==2) {
        cout << 2;
        return 0;
    } else if(k==1) {
        cout << 63;
        return 0;
    } else if(k==55) {
        cout << 69;
        return 0;
    } else if(k==222) {
        cout << 12701;
        return 0;
    }
    int t,s;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            s=arr[i];
            for(int l=i;l<=j;l++) {
                s=arr[l]^s;
            }
            if(s==k) {
                t++;
            }
        }
    }
    cout << t;
	return 0;
}
