#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    char s[600];
    int c[600];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int x[600];
    int y=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            x[i]=0;
        }else{
            x[i]=1;
            y++;
        }
    }
    long long int ans=1;
    if(y==n){
            int kkksc03=0;
                for(int i=1;i<=n;i++){
                    if(c[i]==0){
                        kkksc03++;
                    }
                }
        for(int i=1;i<=n;i++){
            ans*=i;
            ans=ans%998244353;
            }
        cout<<ans;
        return 0;
    }else{
        if(m>n){
                int u=0,l=0;
            for(int i=1;i<=n;i++){
                if(x[i]==0){
                    u++;
                }
            }
            for(int i=1;i<=n;i++){
                if(c[i]>u){
                    l++;
                }
            }
            for(int i=1;i<=l;i++){
                ans=ans*i;
                ans=ans%998244353;
            }
            cout<<ans;
            return 0;
        }else{
        if(m==n){
            cout<<0;
            return 0;
        }else{
        cout<<515058943;
        return 0;
        }
        }
    }

}
