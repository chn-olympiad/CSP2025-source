#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long read(){
    long long m=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        m=(m<<3)+(m<<1)+(ch^48);
        ch=getchar();
    }
    return m*f;
}
int a[5005];
int id[5005];
long long muti(int f,int e){
    int res=1;
    for(int i=f;i<=e;i++){
        res*=i;
        //res%=mod;
    }
    return res;
}
long long cnt=0;
int n;
void dfs(int sum,int l,int k,int maxn){//last , fenshu ,
    if(k==0){
        if(sum>2*maxn){
            cnt++;
        }
        cnt%=mod;
        return ;
    }
    for(int i=l+1;i<=n-k+1;i++){
        dfs(sum+a[i],i,k-1,max(maxn,a[i]));
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    int maxn=-1;
    for(int i=1;i<=n;i++){
        a[i]=read();
        maxn=max(a[i],maxn);
        id[i]=i;
    }
    if(n==3){
        int sum=0;
        for(int i=1;i<=n;i++) sum+=a[i];
        if(sum>2*maxn) cout<<1;
        else cout<<0;
        return 0;
    }
    if(maxn==1&&n>20){
       long long ans=0;
       for(int i=3;i<=n;i++){
            if(n<=30)ans+=(muti(i+1,n)/muti(1,n-i))%mod;
            ans%=mod;
       }
       cout<<ans;
       return 0;
    }else{
        for(int i=3;i<=n;i++){
            dfs(0,0,i,-1);
            cnt%=mod;
        }
        cout<<cnt%mod;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
