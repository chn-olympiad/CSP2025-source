#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N*N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    cin>>a[1];
    x=a[1];
    for (int i=2;i<=n*m;i++)cin>>a[i];
    sort(a+1,a+n*m+1);
    int k=n*m-(lower_bound(a+1,a+n*m+1,x)-a)+1;
    int a=k/n;
    int b=k%n;
    if (b!=0){
        a++;
        if (a%2==1)cout<<a<<" "<<b;
        else cout<<a<<" "<<n-b+1;
    }
    else{
        if (a%2==1)cout<<a<<" "<<n;
        else cout<<a<<" "<<1;
    }
    return 0;
}
