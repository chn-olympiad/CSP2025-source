#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[510],c[510],p[510],all;
int dp[20][20][270000];
bool f[510],fl,fla;
int ans(){
    int q=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            q++;
            continue;
        }else{
            if(c[p[i]]<=q){
                q++;
                continue;
            }
            cnt++;
        }
    }
    return cnt;
}
void dfs(int x){
    if(x>n){
        if(ans()>=m)all++,all%=998244353;
        return;
    }
    for(int i=1;i<=n;i++){
        if(f[i])continue;
        f[i]=true;
        p[x]=i;
        dfs(x+1);
        p[x]=0;
        f[i]=false;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char s;
        cin>>s;
        a[i]=s-'0';
        if(s=='0')fl=true;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0)fla=true;
    }
    if(n<=13){
        dfs(1);
        cout<<all<<'\n';
    }else if(m==n){
        if(fl==true||fla==true)cout<<"0\n";
        else{
            int ad=1;
            for(int i=1;i<=n;i++)ad=(ad*i)%998244353;
            cout<<ad<<'\n';
        }
    }else if(n<=18){
        dp[0][0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<(1<<n);k++){
                    int sum=0,kk=k;
                    while(kk){
                        sum+=kk%2;
                        kk/=2;
                    }
                    if(sum!=i)continue;
                    kk=k;
                    for(int u=0;u<n;u++,kk/=2){
                        if(kk%2==0)continue;
                        if(i-j-1>=c[u+1]||a[i]==0||c[u+1]==0)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k^(1<<u)])%998244353;
                        else if(j!=0)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-1][k^(1<<u)])%998244353;
                    }
                }
            }
        }
        int sd=0;
        for(int i=m;i<=n;i++)sd=(sd+dp[n][i][(1<<n)-1])%998244353;
        cout<<sd<<'\n';
    }
    return 0;
}
