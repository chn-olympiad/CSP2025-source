#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
    return a>b;
}
int a[10005];
int n,m,ans;
int k=1;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) {
        cin>>a[i];
    }
    ans=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++) {
        if(i%2!=0) {
            for(int j=1;j<=m;j++) {
                if(a[k]==ans) {
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        } else {
            for(int j=m;j>=1;j--) {
                if(a[k]==ans) {
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        }
    }
    return 0;
}
