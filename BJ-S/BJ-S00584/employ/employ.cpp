#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,m,c[505],f=0,ff=0,p[505],vis[505];
long long ans;
string s;
long long q(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1){
            ans=ans*a%P;
        }
        a=a*a%P;
        b>>=1;
    }
    return ans;
}
bool check(){
    int b=0,l=0;
    //崩溃/录用人数
    //for(int i=1;i<=n;i++){
    //    cout<<p[i]<<" ";
    //}
    //cout<<endl;
    for(int i=1;i<=n;i++){
        if(p[i]<=b){
            b++;
            continue;
        }
        if(s[i-1]=='1'){
            l++;
        }
        else{
            b++;
        }
        if(l==m){
            break;
        }
    }
    //cout<<l<<endl;
    if(l==m)return 1;
    return 0;
}
void dfs(int x){
    if(x>n){
        ans+=check();
        ans=ans%P;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1)continue;
        p[x]=c[i];
        vis[i]=1;
        dfs(x+1);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0)ff=1;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!='1'){
            f=1;
            break;
        }
    }
    if(f==0&&ff==0){
        cout<<q(2,m);
    }
    else{
        dfs(1);
        cout<<ans;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
