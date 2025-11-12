#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod=998244353;
int a[505],num[]={0,1,2,3,4,5,6,7,8,9,10},res,ord[15];
bool vis[15];
string s;
bool check(){
    int fc=0,ap=0;
    for(int i=1;i<=n;i++){
        int per1=ord[i];
        if(fc>=a[per1]){
            fc++;
            continue;
        }else{
            if(s[i]=='1'){
                ap++;
            }else{
                fc++;
            }
        }
    }
    if(ap>=m) return true;
    return false;
}
void dfs(int pos){
    if(pos==n){
        if(check()){
            res++;
        }
        return;
    }else{
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            vis[i]=true;
            ord[pos+1]=i;
            dfs(pos+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    bool op1=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(s[i]=='0'){
            op1=false;
        }
    }
    if(op1){
        long long res1=1;
        for(int i=1;i<=n;i++){
            res=res*((n-i)+1);
            res=res%mod;
        }
        cout<<res;
    }else if(m==n){
        cout<<1;
    }
    else{
    vector<int > v1;
    dfs(0);
    cout<<res<<endl;
    }
}

