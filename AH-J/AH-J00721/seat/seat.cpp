#include<bits/stdc++.h>
using namespace std;

int n,m,r;
int a[110];

bool cmp(int a,int b) {
    return a>b;
}

int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) {
        cin>>a[i];
        if(i==1) {
            r=a[i];
        }
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++) {
        if(a[i]==r) {
            r=i;
            break;
        }
    }
    if(r<=n){
        cout<<1<<" "<<r;
    }
    else {
        int lie=(r-1)/n+1;
        cout<<lie<<" ";
        if(lie%2==0)
        cout<<n*lie-r+1;
        else
        cout<<r-(lie-1)*n;
    }
    return 0;
}
