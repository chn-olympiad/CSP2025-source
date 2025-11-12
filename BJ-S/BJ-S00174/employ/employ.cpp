#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],cs[505],b[505],a[505],t,l,p,ans,ms,z,q1;
string s;
int dfs(int ss){
    if(ss>n){
            z++;
        t=0;
        ms=0;
        for(int j=1;j<=n;j++){
            cs[j]=c[j];
        }
        for(int i=1;i<=n;i++){
            if(t>=cs[a[i]]){
                t++;
                cs[a[i]]=1000;
            }

            if(s[i-1]=='0'&&cs[a[i]]!=1000){
                cs[a[i]]=1000;
                t++;
            }
            else if(cs[a[i]]!=1000){
                cs[a[i]]=1000;
                ms++;
            }
        }
        if(ms>=m){
            ans++;
            for(int i=1;i<=n;i++){
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            b[i]=1;
            a[ss]=i;
            dfs(ss+1);
            b[i]=0;
        }
    }
    return 0;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            q1++;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(q1==n){
        ans=1;
        for(int i=1;i<=n;i++){
            ans=(ans*(n-i+1))%998244353;
        }
        cout<<ans;
        return 0;
    }
    dfs(1);
    cout<<ans;
    return 0;
}
