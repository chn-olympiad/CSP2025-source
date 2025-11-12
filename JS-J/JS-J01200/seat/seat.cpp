#include<bits/stdc++.h>
using namespace std;
int n,m,sum,ans,a[109],b[19][19];
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) {
        cin>>a[i];
    }
    sum=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++) {
        if(a[i]==sum) ans=n*m-i;
    }
    int i=1,j=1;
    while(1) {
        while(i+1<=n&&ans) {
            ans--;
            i++;
            if(ans==0) {
                cout<<j<<" "<<i;
                return 0;
            }
        }
        if(i==n&&ans) {
            j++;
            ans--;
            if(ans==0) {
                cout<<j<<" "<<i;
                return 0;
            }
        }
        while(i-1>=1&&ans) {
            ans--;
            i--;
            if(ans==0) {
                cout<<j<<" "<<i;
                return 0;
            }
        }
        if(i==1) {
            if(ans==0) {
                cout<<j<<" "<<i;
                return 0;
            }
            j++;
            ans--;
        }
    }
    return 0;
}
