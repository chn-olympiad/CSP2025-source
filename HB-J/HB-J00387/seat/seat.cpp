#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1005],k,l=0;
    cin>>n>>m;
    for(int i=0;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[0];
    sort(a,a+n*m);
    for(int i=n*m;i>=0;i--){
        if(a[i]>k){
            l++;
        }
    }
    int p=(l-l%n)/n+1;
    if(p%2==0){
       cout<<p<<" "<<n-(l%n);
    }
    else{
        cout<<p<<" "<<l%n+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
