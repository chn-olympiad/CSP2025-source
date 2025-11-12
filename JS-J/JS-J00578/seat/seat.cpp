#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1];
    int big=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i>1&&a[i]>a[1])big++;
    }
    int w=big+1;
    int k=(w-1)/n;
    int q=w%n;
    if(q==0)q=n;
    cout<<k+1<<' ';
    if(k%2==0)cout<<q;
    else cout<<n-q+1;
    return 0;
}
