#include <iostream>
#include <cstdlib>
#define MOD 998244353
using namespace std;

const int N=505;

int n,m;
bool s[N];
int c[N];

bool chosen[N];
int p[N],ans;
void dfs(int cur){
    if(cur>n){
        int ctot=0,cnt=0;
        for(int i=1;i<=n;++i){
            if(ctot>=c[p[i]] || !s[i]){
                ++ctot;
            }else{
                ++cnt;
            }
        }ans+=(cnt>=m);
        return ;
    }for(int i=1;i<=n;++i){
        if(!chosen[i]){
            chosen[i]=true;
            p[cur]=i;
            dfs(cur+1);
            chosen[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;++i){
        char c;
        cin>>c;
        s[i]=(c=='1');
    }for(int i=1;i<=n;++i){
        cin>>c[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
