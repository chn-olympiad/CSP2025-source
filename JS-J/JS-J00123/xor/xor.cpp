#include<bits/stdc++.h>
using namespace std;
int a[500001],k,n,b[500001],ans=0;
inline void dfs(int f,int sum){
    if(f+1<=n) dfs(f+1,sum);
    else{
        ans=max(ans,sum);
    }
    if(b[f]!=-1) dfs(b[f]+1,sum+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(b,-1,sizeof(b));
    for(int i=1;i<=n;i++){
        int check=a[i];
        if(a[i]==k) b[i]=i;
        else{
            for(int j=i+1;j<=n;j++){
                check^=a[j];
                if(check==k){
                    b[i]=j;
                    continue;
                }
            }
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
