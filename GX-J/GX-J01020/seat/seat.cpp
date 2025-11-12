#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,k,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>k;
        if(i==1){
            r=k;
        }else if(k>r){
        ans++;
        }
    }//cout<<(ans-1)/n+1;
    if(((ans-1)/n+1)%2==1){
    if(ans%n==0){
    cout<<(ans-1)/n+1<<" "<<n;
    }else{
    cout<<(ans-1)/n+1<<" "<<(ans%n);
    }
    }else{
    if(ans%n==0){
    cout<<(ans-1)/n+1<<" "<<1;
    }else{
    cout<<(ans-1)/n+1<<" "<<n-((ans-1)%n);
    }
    }
    return 0;
}
