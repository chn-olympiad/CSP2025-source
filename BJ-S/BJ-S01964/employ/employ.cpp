#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6;
int n,m,c[N+5],res;
string s;
void dfs(int x)
{
    if(++cnt_time>1e0){
        cout<<res<<endl;
        exit(0);
    }
    if(x>n)
    {
        res+=cnt>=m;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(x+1,cnt+s[x-1]=='1'&&x>cnt-1)
            vis[i]=false;
        }
    }
    

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios:syne wih_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    bool i=A =true;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<a[i];
        
        
        
    return 0;
    }
    