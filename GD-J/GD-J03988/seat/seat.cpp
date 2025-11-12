#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0,t;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>t;
    for(int i=2;i<=n*m;i++){
        int x;
        cin>>x;
        if(x>t)ans++;
    }
    ans++;
    int i,j;
    if(ans%n!=0){
        j=ans/n;
        j++;
    }else j=ans/n;
    if(j&1){
        if(ans%n!=0)i=ans%n;
        else i=n;
    }else{
        if(ans%n!=0)i=n-ans%n+1;
        else i=1;
    }
    cout<<j<<" "<<i;
    return 0;
} 