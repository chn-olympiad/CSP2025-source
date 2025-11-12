#include<bits/stdc++.h>
using namespace std;
const int N=5005;
string s;
int c[N];
bool flag[N];
int n,m;
long long cnt=0;
void dfs(int now,int ok){
    if(now>n){
        if(ok>=m){
            cnt++;
        }
        return ;
    }
    if(m-ok>n-now+1){
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            flag[i]=1;
            dfs(now+1,ok+(now-1-ok>=c[i] ? 0:(s[now]=='1' ? 1:0)));
            flag[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    dfs(1,0);
    printf("%d\n",cnt%998244353);
    return 0;
}

