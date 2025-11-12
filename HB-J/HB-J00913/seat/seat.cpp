#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a[m*n]={0};
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a,a+m*n+1);
    int k;//zheng
    for(int i=1;i<=m*n;i++){
        if(x==a[i]){
            k=i;
            break;
        }
    }
    k=m*n-k+1;//dao
    int ans1=k/n+1;
    if(k%n==0){
        ans1=k/n;
        cout<<ans1<<" "<<n;
        return 0;
    }
    cout<<ans1<<' ';
    if(ans1%2==0){
        cout<<n-k%n+1;
    }
    else cout<<k%n;
    return 0;
}
