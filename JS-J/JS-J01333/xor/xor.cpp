#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
class node{
public:
    int l,r;
}q[MAXN];
bool cmp(node x,node y){return x.r<y.r;}
int cnt,a[MAXN];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int la=0;
        for(int j=i;j<=n;j++){
            la=la^a[j];
            if(la==k){
                q[++cnt].l=i,q[cnt].r=j;
                break;
            }
        }
    }
    sort(q+1,q+1+cnt,cmp);
    int lar=0,ans=0;
    for(int i=1;i<=cnt;i++)
        if(q[i].l>lar){
            ans++;
            lar=q[i].r;
        }
    cout<<ans;
    return 0;
}
