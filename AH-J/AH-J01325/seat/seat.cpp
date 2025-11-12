#include <bits/stdc++.h>
using namespace std;
int seat[20][20],a[110];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n*m;i++) {
        cin >> a[i];
    }
    int c=a[0],i=0,j=0;
    sort(a,a+n*m);
    for (int k=n*m-1;k>=0;k--) {
        seat[i][j] = a[k];
        if (seat[i][j] == c) {
            cout << j+1 << " " << i+1 << endl;
            break;
        }
        i++;
        if (i >= n) {
            j++;
            if ((j+1) % 2 == 0) {
                i = n-1;
            } else {
                i=0;
            }
        }
        if (j >= m) {
            break;
        }
    }
    return 0;
}
