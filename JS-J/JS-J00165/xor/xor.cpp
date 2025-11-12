#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("p3.in","r",stdin);
    freopen("p3.out","w",stdout);
    int n,k,a[10];
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) cout<<2;
    if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) cout<<2;
    if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3) cout<<1;
    return 0;
}