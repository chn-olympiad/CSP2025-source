#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int s[N],c[N],b[N];
int n,m,maxn,minn,cnt;
void dfs(int step,int p,int h){
    if(step>n){
        if(p>=m) cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]){
            b[i]=1;
            if(h<c[i]&&s[step]==1) dfs(step+1,p+1,h);
            else dfs(step+1,p,h+1);
            b[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s1;
    cin>>s1;
    for(int i=0;i<s1.size();i++){
        s[i+1]=s1[i]-'0';
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1,0,0);
    cout<<cnt;
    return 0;
}