#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005],vis[5005],sum,tot,t,ans,y;
void find(int x){
    if(y>1&&sum<=a[x]) return;
    if(y==t){
        if(sum>a[x]*2){
            tot++;
        }

        tot=tot%N;
        return;
    }
    for(int i=x;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            y++;
            sum+=a[i];
            find(i);
            y--;
            vis[i]=0;
            sum-=a[i];
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
        tot=0;
        sum=0;
        t=i;
        y=0;
        find(1);
        ans=(ans+tot)%N;
    }
    cout<<ans;
    return 0;
}
