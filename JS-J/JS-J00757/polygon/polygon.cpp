#include<bits/stdc++.h>
using namespace std;
int s[5001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum = 0,maxer = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        sum+=s[i];
        maxer = max(maxer,s[i]);
    }
    if(n==3){
        if(sum>maxer*2){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<n/2+2;
    }
    return 0;
}
