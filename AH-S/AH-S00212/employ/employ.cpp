#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],mod=998244353,ans,p[505],f[400005][30];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    if(m==n){
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||c[i]==0){
                cout<<0;
                return 0;
            }
        }
        ans=1;
        for(int i=1;i<=n;i++)ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    /*for(int i=1;i<=n;i++)p[i]=i;
    do{
        int fail=0,suc=0;
        for(int i=1;i<=n;i++){
            if(fail>=c[p[i]]||s[i]=='0')fail++;
            else suc++;
        }
        if(suc>=m)ans++;
    }while(next_permutation(p+1,p+n+1));*/
    f[0][0]=1;
    for(int i=0;i<(1<<n);i++){
        int num=0,tmp=i;
        while(tmp){
            num++;
            tmp-=tmp&-tmp;
        }
        for(int j=0;j<=num;j++){
            for(int k=1;k<=n;k++){
                if(((1<<(k-1))&i)==0){
                    if(num-j<c[k]&&s[num+1]=='1'){
                        f[i+(1<<(k-1))][j+1]+=f[i][j];
                        f[i+(1<<(k-1))][j+1]%=mod;
                    }else{
                        f[i+(1<<(k-1))][j]+=f[i][j];
                        f[i+(1<<(k-1))][j]%=mod;
                    }
                }
            }
        }
    }
    for(int i=m;i<=n;i++){
        ans=(ans+f[(1<<n)-1][i])%mod;
    }
    cout<<ans;
    return 0;
}

