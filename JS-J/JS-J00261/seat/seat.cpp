#include<bits/stdc++.h>
using namespace std;
int n,m,ss,x=0;
int s[111];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
        if(i==1)ss=s[i];
    }
    sort(s+1,s+n*m+1);
    for(int i=n*m;i>=1;i--){
        x++;
        if(s[i]==ss)break;
    }
    int ff=x/n;
    if(x%n!=0){
        ff+=1;
    }
    cout<<ff<<' ';
    if(ff%2!=0){
        if(x%n==0)cout<<n;
        else cout<<x%n;
    }else{
        if(x%n==0)cout<<1;
        else cout<<n-x%n+1;
    }
    return 0;
}
//97 98 99 100
