#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum[5000][5000],w,ans,f[50010],fb,fa;
struct node{
    int x,y;
};
node id[3010];
bool cmp1(node x,node y){
    return x.y-x.x<y.y-y.x;
}
bool pd(int l,int r){
    for(int i=l; i<=r; i++){
        if(f[i]==1){
            return 0;
        }
    }
    for(int i=l; i<=r; i++){
        f[i]=1;
    }
    return 1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum[i][i]=a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            sum[i][j]=sum[i][j-1]^a[j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(sum[i][j]==k){
                id[++w].x=i;
                id[w].y=j;
            }
        }
    }
    sort(id+1,id+1+w,cmp1);
    for(int i=1; i<=w; i++){
        if(pd(id[i].x,id[i].y)){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
