#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int s[505],c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int flag=0;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        if(x=='1') s[i]=1;
        else s[i]=0;
        if(s[i]==0) flag=1;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    if(flag==0){
        cout<<0;
    }else{
        int p[505],ans=0;
        for(int i=1;i<=n;i++){
            p[i]=i;
        }
        do{
            int cntleave=0,go=0;
            for(int i=1;i<=n;i++){
                if(s[i]==0||c[p[i]]<=cntleave){
                    cntleave++;
                }else{
                    go++;
                }
                if(go>=m) break;
            }
            if(go>=m){
                ans++;
                ans%=mod;
            }
        }while(next_permutation(p+1,p+n+1));
        cout<<ans;
    }
    return 0;
}
