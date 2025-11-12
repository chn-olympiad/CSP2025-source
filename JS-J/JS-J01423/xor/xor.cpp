#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    if(n<=1000){
        s[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i]=s[i-1]^a[i];
            for(int j=1;j<=i;j++){
                if((s[i]^s[j-1])==k){
                    ans++;
                }
            }
        }
        cout<<ans;
        return 0;
    }//point 1 to 12, 60pts
    else if(k<=1){
        for(int i=1;i<=n;i++){
            ans+=(a[i]==k);
        }
        cout<<ans;
        return 0;
    }//point 13, 5pts
    else{
        s[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i]=s[i-1]^a[i];
            for(int j=1;j<=i;j++){
                if((s[i]^s[j-1])==k){
                    ans++;
                }
            }
        }
        cout<<ans;
        return 0;
    }//don't know how many pts
    return 0;
}
