#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N],cnt=0;
bool vis[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(k==0&&a[i]==0) cnt++;
    }
    if(k==0){
        cout<<cnt;
        return 0;
    }
    int i=1,x=0;
    memset(vis,0,sizeof vis);
    vis[0]=1;
    while(i<=n){
        x=x^a[i];
        vis[a[i]]=1;
        vis[x]=1;
        if(vis[x^k]){
            memset(vis,0,sizeof vis);
            vis[0]=1;
            x=0;
            cnt++;
        }
        i++;
    }
    cout<<cnt;
    return 0;
}
