#include <iostream>
#include <algorithm>
using namespace std;

int a[110];

int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) {
        cin>>a[i];
    }
    int b=a[1];
    sort(a+1,a+n*m+1);
    int bs;
    for (int i=1;i<=n*m;i++) {
        if (a[i]==b) {
            bs=i;
            break;
        }
    }
    bs=n*m-bs+1;
    int c=(bs-1)/n+1;
    if (c%2==0) {
        cout<<c<<" "<<m-(bs-c*n+c)+1;
    }
    else {
        cout<<c<<" "<<bs-(c-1)*n;
    }
    return 0;
}