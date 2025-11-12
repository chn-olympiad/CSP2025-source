#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a[510],sum,ans[10000]={1},len=1,x[3],xlen,res[10000],aans,now[510];
string s;
bool f[510];
void dfs(int x){
    if(x==n+1){
        int ssum=0,res=0;
        for(int i=1;i<=n;i++){
            if(a[now[i]]<=ssum||s[i]=='0')ssum++;
            else res++;
        }
        if(res>=m)aans++;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            f[i]=1;
            now[x]=i;
            dfs(x+1);
            f[i]=0;
        }
    }
}
void add(int k){
    memset(res,0,sizeof(res));
    sum=k,xlen=0;
    while(sum>0){
        x[xlen++]=sum%10;
        sum/=10;
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<xlen;j++){
            res[i+j]+=ans[i]*x[j];
            res[i+j+1]+=res[i+j]/10;
            res[i+j]%=10;
        }
    }
    while(res[len]>0)len++;
    memcpy(ans,res,sizeof(ans));
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        sum+=s[i]-'0';
    }
    //cout<<sum<<endl;
    if(n<=20){
        dfs(1);
        cout<<aans<<endl;
    }
    if(sum==n){
        aans=0;
        int ssum=0;
        for(int i=1;i<=n;i++){
            add(i);
            if(a[i]==0)ssum++;
        }
        for(int i=len-1;i>=0;i--){
            aans=aans*10+ans[i];
            aans%=mod;
        }
        if(n-ssum<m)cout<<0<<endl;
        else cout<<aans<<endl;

    }else cout<<0<<endl;
    return 0;
}
