#include<bits/stdc++.h>
using namespace std;
int m,n,a[1001],h;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int k=0,ans=0;
    k=a[1];
    sort(a+1,a+1+m*n);
    for(int i=m*n;i>=1;i++){
        ans++;
        if(a[i]==k){
           h=ans;
        }
    }
    cout<<(h-1)/n+1<<" ";
    if(((h-1)/n+1)%2==0){
       cout<<n+1-h%n;
    }
    else {
        cout<<h%n;
    }
    return 0;
}
