#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans,xo;
int a[N];
bool vis[N],f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==k){
            ans++;
            vis[i]=1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int l=1;l<=(n-i+1);l++){
            xo=a[l];
            f=0;
            for(int x=l;x<=(l+i-1);x++){
                if(vis[x]){
                    f=1;
                    break;
                }
                if(x>l) xo=(xo xor a[x]);
            }
            if(f==0 && xo==k){
                ans++;
                for(int x=l;x<=(l+i-1);x++) vis[x]=1;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
