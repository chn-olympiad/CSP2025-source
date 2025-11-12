#include <iostream>
using namespace std;
const int N=510;
const int INF=998244353;
#define int long long
int n,m;
char a[N];
int b[N],flag[N];
int res;
void dfs(int x,int y){
    if(x==n){
        if(y>=m){
            res++;
            res%=INF;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            flag[i]=1;
            if(x-y>=b[i] || a[x+1]=='0'){
                dfs(x+1,y);
            }
            else{
                dfs(x+1,y+1);
            }
            flag[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>(a+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    dfs(0,0);
    cout<<res<<"\n";
    return 0;
}
