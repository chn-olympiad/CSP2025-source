#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010010],b[1011][1010],cnt;
struct node{
    long long l,r;
}tx[1001011];
bool cmp(node x,node y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[i][j]=b[i][j-1]^a[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[i][j]==m){
                cnt++;
                tx[cnt].l=i;
                tx[cnt].r=j;
            }
        }
    }
    sort(tx+1,tx+cnt+1,cmp);
    long long zx=-1e18,ans=0;
    for(int i=1;i<=cnt;i++){
        if(tx[i].l>zx){
            zx=tx[i].r;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
