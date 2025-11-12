#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k,l,c=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        k=a[1];
    }
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(k==a[i]){
            break;
        }
        l++;
        if(l>n){
            l=l-c*n;
            c++;
        }

    }
    cout<<c<<" "<<l;
    return 0;
}
