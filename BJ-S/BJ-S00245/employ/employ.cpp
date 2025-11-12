#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int n,m,a[N],cnt=0,vis[N],b[N],c[N],ct[N];
string s;
bool check(){
    int yj=0,tot=0;
    for(int i=1;i<=n;i++){
    //    cout<<"i "<<i<<" "<<b[i]<<" "<<yj<<" "<<tot<<endl;
        if(yj>=c[b[i]]){
            yj++;
            continue;
        }
        if(a[i]==0){
            yj++;
            continue;
        }
        tot++;
    }
 //   cout<<tot<<endl;
    if(tot>=m) return 1;
    return 0;
}
void dfs(int x){
    if(x>n){
        if(check()) cnt++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            b[x]=i;
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
void work1(){
    dfs(1);
    cout<<(cnt%mod+mod)%mod<<endl;
}
void work2(){
    int ans1=1;
    for(int i=1;i<=n;i++){
        ct[c[i]]++;
        ans1=ans1*i%mod;
    }
    for(int i=1;i<=n;i++){
        ct[i]+=ct[i-1];
    }
    int ans=1,c1=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0) continue;
        c1++;
        if(ct[i-1]<c1){
            ans=0;
            break;
        }
     //   cout<<"i "<<i<<" "<<ct[i-1]-c1+1<<endl;
        ans*=(ct[i-1]-c1+1);
        ans%=mod;
    }
    for(int i=1;i<=n-c1;i++){
        ans=ans*i%mod;
    }
 //   cout<<ans<<endl;
    cout<<((ans1-ans)%mod+mod)%mod<<endl;
}
void work3(){
    int rt=1;
    for(int i=1;i<=n;i++){
        rt=rt*i%mod;
    }
    cout<<(rt%mod+mod)%mod<<endl;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++) a[i+1]=s[i]-'0';
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n<=10){
        work1();
    }else if(m==1){
        work2();
    }else work3();
    return 0;
}