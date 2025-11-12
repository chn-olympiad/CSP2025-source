#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5,M=998244353;
#define int ll
/*
s1<=18 bruteforce over s1 to try which are ok

*/

int n,m;
char s[N];
int c[N],p[N],jc[N];
int cf[N],g[N],f[N];
int ansg[N],ansf[N];
int bp[N];
void sl(){
    int cnt=0;
    vector<int> a;
    for(int i=1;i<=n;i++)a.push_back(i);
    do{
        int c0=0,f=0,j=1;
        for(auto i:a){
            if(s[j]=='1' and c[i]>c0)f++;
            else c0++;
            j++;
        }
        cnt+=(f>=m);
    }while(next_permutation(a.begin(),a.end()));
    cout<<cnt<<endl;
}
int ans=0;
int lowbit(int x){return x&-x;}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=(1<<18);i++)bp[i]=bp[i-lowbit(i)]+1;
    for(int i=1;i<=n;i++)cin>>s[i],cnt+=(s[i]=='1');
    for(int i=1;i<=n;i++)cin>>c[i],cf[c[i]]++;
    if(n<=10){
        sl();return 0;
    }
    for(int i=1;i<=n;i++){
        cf[i]+=cf[i-1];
    }
    jc[0]=1;
    for(int i=1;i<=n;i++)jc[i]=(jc[i-1]*i)%M;
    if(cnt==n){
        cout<<jc[N]<<endl;
        return 0;
    }
    if(m==n){
        cout<<0<<endl;
        return 0;
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1')p[++cnt]=i;
    }ans=0;
    for(int i=0;i<(1<<cnt);i++){
        if(bp[i]<m)continue;
        cerr<<i<<endl;
        for(int j=1;j<=cnt;j++){
            g[j]=g[j-1]+(p[j]-p[j-1]-1)+((i&(1<<(j-1))?0:1));
            cerr<<g[j]<<" ";
        }
        f[cnt+1]=1;int t1=0;
        for(int j=cnt;j>=1;j--){
            if(i&(1<<(j-1)))f[j]=f[j+1]*max(0ll,cf[n]-cf[g[j]]-t1)%M,t1++;
            else f[j]=f[j+1];
            cerr<<i<<" "<<j<<" "<<f[j]<<" "<<t1<<endl;
        }
        f[1]*=jc[n-t1];f[1]%=M;
        ansg[i]=f[1];
    }
    for(int i=0;i<(1<<cnt);i++){
        if(bp[i]<m)continue;
        for(int j=i;j>0;j&=(j-1)){
            bp[i^j]%2?ansf[j]-=ansg[i]:ansf[j]+=ansg[i];
            ansf[j]+=M;if(ansf[j]>=M)ansf[j]-=M;
        }
    }
    for(int i=0;i<(1<<cnt);i++){
        cerr<<ansg[i]<<" ";
        if(bp[i]>=m){ans+=ansf[i],ans%=M;}
    }
    cout<<ans<<endl;
    return 0;
}