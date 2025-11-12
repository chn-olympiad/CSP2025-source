#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],k,x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            x=i;
        }
    }
    cout<<(x-1)/n+1<<" ";
    if(((x-1)/n+1)%2==0){
        cout<<n-(x-1)%n;
    }
    else{
        cout<<(x-1)%n+1;
    }
    return 0;
}
