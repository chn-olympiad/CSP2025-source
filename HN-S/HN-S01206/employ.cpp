#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=501;
int n,c[N],m,ans;
int p[N];
char s[N];
void dfs(int x,int sum){
    if(x>n){
        if(sum>=m){
            ans++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(p[i]==0){
            p[i]=x;
            if(x-1-sum>=c[i]||s[x]=='0')dfs(x+1,sum);
            else dfs(x+1,sum+1);
            p[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}