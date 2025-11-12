#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,K=1<<21;
int n,k,l,ans,lst,a[N],s[N],vis[K];
struct F{
    int x,y;
}f[N<<1];
bool cmp(F p,F q){
    return p.y!=q.y?p.y<q.y:p.x>q.x;
}
int main(){
    freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k,vis[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i],s[i]=s[i-1]^a[i];
        if(a[i]==k) f[++l]={i,i};
        if(i>1&&vis[s[i]^k]) f[++l]={vis[s[i]^k],i};
        vis[s[i-1]]=i;
    }
    sort(f+1,f+l+1,cmp);
    for(int i=1;i<=l;i++)
        if(f[i].x>lst) lst=f[i].y,++ans;
    cout<<ans;
    return 0;
}