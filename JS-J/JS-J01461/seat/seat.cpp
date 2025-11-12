#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>a[i];

    }
    int bh=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]==bh) bh=n*m-i+1;
    }
    int l=bh/n,h=bh%n;
    if(bh%n!=0) l++;
    if(h==0) h=n;
    if(l%2==0) h=n-h+1;
    cout<<l<<" "<<h;
    return 0;
}
