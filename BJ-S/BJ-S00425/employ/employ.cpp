#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505],b[505],flag,sum;
long long ans,mod=998244353;
bool bo[20];
int c[20];
long long j[505];
void innt(){
    ans=1;
    j[0]=1;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=mod;
        j[i]=ans;
    }
    ans=0;
}
void dfs(int x,int num,int summ){
    if(x>n+1) return ;
    if(summ>=m){
        ans+=j[n+1-x];
        ans%=mod;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!bo[i]){
            bo[i]=1;
            if(b[x]==0||(num>=a[i])) num++;
            else summ++;
            dfs(x+1,num,summ);
            if(b[x]==0||(num>=a[i])) num--;
            else summ--;
            bo[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    innt();
    cin>>s;
    for(int i=0;i<s.size();i++){
        b[i+1]=s[i]-'0';
        if(b[i+1]==1) flag++;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) sum++;
    }
    if(n-sum<m){
        cout<<0;
        return 0;
    }
    if(n==m){
        cout<<0;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}