#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n,y=0;
    cin>>m>>n;
    string a;
    cin>>a;
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        if(b>0){
            y+=1;
        }
    }
    long long int ans=1;
    for(int i=y;i>0;i--){
        ans*=i;
        ans=ans%998244353;
    }
    if(y<n){
        ans=0;
    }
    cout<<ans;

    return 0;
}
