#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=m*n;
    for(int i=1;i<=k;i++) cin>>a[i];
    int x=a[1];
    sort(a+1,a+k+1);
    for(int i=1;i<=k;i++){
        if(x==a[i]) x=i;
    }
    int f=m-floor((x-0.1)/n);
    int g=x%n;
    if(f%2==1&&g==0) g=n;
    else if(f%2==0&&g==0) g=n;
    if(f%2==1) g=n+1-g;
    cout<<f<<" "<<g;
    return 0;
}
