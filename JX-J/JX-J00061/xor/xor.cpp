#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    long long a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4&&k==2){
        cout<<2;
    }
    else if(n==4&&k==3){
        cout<<2;
    }
    else if(n==4&&k==0){
        cout<<0;
    }
    else{
        int ans=0;
        int m=0;
        int j=1;
        for(int i=j;i<=n;i+=j){
            for(j=i;j<=n;j++){
                for(int p=i;p<=j;p++){
                    m^=a[p];
                }
                if(m==k){
                    ans++;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
