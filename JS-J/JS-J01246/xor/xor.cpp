#include<bits/stdc++.h>
using namespace std;
int n,k,v,cnt,a[550000],pre[550000];
bool vis[550000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
    }
    for(int i=1;i<=n;++i){
        if(vis[i]){
            continue;
        }
        for(int j=i;j<=n;++j){
            if(vis[j]){
                break;
            }
            if((pre[j]^pre[i-1])==k){
                if(i==j&&a[i]!=k){
                    continue;
                }
                ++cnt;
                for(int l=i;l<=j;++l){
                    vis[l]=1;
                }
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
