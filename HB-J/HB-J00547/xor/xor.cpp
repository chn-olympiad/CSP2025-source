#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],book,f,ans;
struct node{
    int l,r;
}q[10000005];
bool cmp(node x,node y){
    if(x.r!=y.r)
        return x.r<y.r;
    return x.l>y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int x=0;
        for(int j=i;j<=n;j++){
            x=(x^a[j]);
            if(x==k)
                q[++f].l=i,q[f].r=j;
        }
    }
    sort(q+1,q+1+f,cmp);
    for(int i=1;i<=f;i++)
        if(book<q[i].l)
            ans++,book=q[i].r;
    cout<<ans;
    return 0;
}
