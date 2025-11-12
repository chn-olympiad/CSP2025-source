#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct Node{
    int l,r;
}t[N];
bool cmp(const Node &x,const Node &y){
    if(x.r!=y.r) return x.r<y.r;
}
int a[N],sum[N],n,m,cnt=1,tot;
vector<int> s[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++) s[sum[i]].push_back(i);
    for(int i=1;i<=n;i++){
        int x=m^sum[i];
        if(sum[i]==m){
            t[++tot].l=1,t[tot].r=i;
        }
        else{
            if(s[x].size()!=0){
                for(int j=0;j<s[x].size();j++){
                   if(s[x][j]!=i) t[++tot].l=min(s[x][j],i),t[tot].r=max(s[x][j],i);
                }
            }

        }
    }
    sort(t+1,t+1+tot,cmp);
    for(int i=1;i<=tot;i++){
       // cout<<t[i].l<<" "<<t[i].r<<endl;
    }
    int r=t[1].r;
    for(int i=1;i<=tot;i++){
        if(t[i].l>r){
            cnt++;
            r=t[i].r;
        }
    }
    cout<<cnt;
    return 0;
}
