#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,k,a[maxn],f[maxn];
struct node{
    int st,ed;
};
node b[maxn*10];
int cnt;
bool cmp(node x,node y){
    return x.ed<y.ed;
}
//60 points
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        f[i]=f[i-1]^a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if((f[j]^f[i-1])==k) b[++cnt]=(node){i,j};
        }
    }
    sort(b+1,b+cnt+1,cmp);
    int ans=0,cur_ed=0;
    for(int i=1;i<=cnt;++i){
        if(b[i].st>cur_ed){
            ++ans;
            cur_ed=b[i].ed;
        }
    }
    cout<<ans;
    return 0;
}
