#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int p=a[0];
    sort(a,a+n*m);
    int s=1;
    for(;a[n*m-s]!=p;s++);
    if((s/n)%2==0){
        cout<<s/n+1<<" "<<s%n;
    }
    else{
        cout<<s/n+1<<" "<<n-s%n+1;
    }
    return 0;
}
