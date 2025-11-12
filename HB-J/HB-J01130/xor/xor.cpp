#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,k;
int a[N];
int sum[N];
int ans;

void dfs(int x,int idx){
    if(x+n-idx<=ans)return;
    ans=max(ans,x);
    if(idx==n)return;
    bool pd=true;
    for(int L=idx+1;L<=n&&pd;++L){
        for(int R=L;R<=n&&pd;++R){
            if((sum[R]^sum[L-1])==k){
                dfs(x+1,R);
                pd=true;
                break;
            }
        }
    }
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}