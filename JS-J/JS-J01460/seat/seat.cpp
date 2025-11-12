#include<bits/stdc++.h>
using namespace std;
int n,m,a[114],k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>a[i];}
    k=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            k=n*m-i+1;
            break;
        }
    }
    cout<<(k-1)/n+1<<' ';
    if((k-1)/n%2==0)cout<<(k-1)%n+1;
    else cout<<n-(k-1)%n;
    return 0;
}
/*8:50*/
