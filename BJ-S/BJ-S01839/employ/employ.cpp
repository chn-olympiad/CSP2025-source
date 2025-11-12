#include<bits/stdc++.h>
using namespace std;
int n,m,k;
string s;
int c[15];
int v[15],a[15];
int ans;
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'||cnt>=c[a[i]]){
            cnt++;
        }
    }
    return cnt<=k;
}
void dfs(int x){
    if(x>n){
        ans+=check();
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            a[x]=i;
            dfs(x+1);
            v[i]=0;
            a[x]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    s=' '+s;
    k=n-m;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}
