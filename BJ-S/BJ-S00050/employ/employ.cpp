#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,m;
string s;
int a[501];
int jc(int n){
    int ans=1;
    for(int i=n;i>=2;i--){
        ans*=i;
        ans%=md;
    }
    return ans;
}
bool check(vector<int> sx){
    int cnt=0;
    int fl=0;
    for(int i=0;i<sx.size();i++){
        if(fl>=a[i]){
            fl++;
            continue;
        }
        if(s[i]=='1') cnt++;
        else fl++;
    }
    return cnt>=m;
}
int res=0;
bool vis[501];
void dfs(int num,vector<int> sx){
    if(num==n){
        res+=check(sx);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            sx.push_back(i);
            dfs(num+1,sx);
            sx.pop_back();
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    bool ff=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!='1') break;
        if(i==s.size()-1){
            ff=1;
        }
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(ff){
        cout<<jc(n);
        return 0;
    }
    dfs(0,{});
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
