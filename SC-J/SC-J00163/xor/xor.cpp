#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6+10;
int n,k,c,l,ans,a[N],t[M];
struct node{
    int l,r;
}q[N];
bool cmp(node x,node y){
    if(x.l!=y.l)return x.l<y.l;
    return x.r<y.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    memset(t,-1,sizeof t),t[0]=1;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]^=a[i-1];
    for(int i=1;i<=n;i++){
        if(t[a[i]^k]&&t[a[i]^k]!=-1){
            q[++c].l=t[a[i]^k];
            q[c].r=i;
        }
        t[a[i]]=i+1;
    }
    sort(q+1,q+c+1,cmp);
    for(int i=1;i<=c;i++){
        if(q[i].l<l){
        	if(q[i].r<l)l=q[i].r+1;
        	continue;
		}
        ans++,l=q[i].r+1;
    }
    cout<<ans;
    return 0;
}