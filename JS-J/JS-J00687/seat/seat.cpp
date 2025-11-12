#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    for(int i=2;i<=n*m;i++)if(a[i]>a[1])cnt++;
    cnt++;
    int r=cnt/n;
    if(cnt%n!=0){
        r++;
        if(r%2==0)cout<<r<<" "<<n-(cnt%n)+1;
        else cout<<r<<" "<<(cnt%n);
    }
    else{
        if(r%2==0)cout<<r<<" "<<1;
        else cout<<r<<" "<<n;

    }

    return 0;
}
