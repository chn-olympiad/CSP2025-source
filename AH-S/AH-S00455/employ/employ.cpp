#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],cni[1005];
long long cnt;
string s;
bool ok,vis[505];
long long k(int n){
    long long sum=1;
    for(int i=1;i<=n;i++){
        sum*=i;
        sum%=998244353;
    }
    return sum;
}
bool ku(int a[]){
    int wei=0,yi=0;
    for(int i=1;i<=n;i++){
        if(wei>=c[i]){
            continue;
        }
        if(s[i-1]=='0'){
            wei++;
        }else{
            yi++;
        }
    }
    if(yi>=m){
        return 1;
    }
    return 0;
}
void dfs(int x,int a[]){
    if(x==n+1){
        if(ku(a)){
            cnt++;
            cnt%=998244353;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            a[x+1]=i;
            vis[i]=1;
            dfs(x+1,a);
            a[x+1]=0;
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            ok=1;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        cni[c[i]]++;
    }
    if(n<=10){
        int b={0};
        dfs(0,{0});
        cout<<cnt;
    }else if(m==1){
        cout<<k(n);
    }else if(ok==0){
        cout<<k(n-cni[0]);
    }else{
        int b={0};
        dfs(0,{0});
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
