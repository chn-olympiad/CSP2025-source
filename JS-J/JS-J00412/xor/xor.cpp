#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,k,tot,lst,res,a[N];
struct node{
    int l,r;
}p[N];
bool cmp(node x,node y){
    if(x.r!=y.r) return x.r<y.r;
    else return x.l<y.l;
}
int get(int s,int e){
    int res=a[s];
    for(int i=s+1;i<=e;i++)
        res^=a[i];
    return res;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(get(i,j)==k){
                tot++;
                p[tot].l=i;
                p[tot].r=j;
            }
    sort(p+1,p+tot+1,cmp);
    res=1;lst=1;
    for(int i=2;i<=tot;i++)
        if(p[i].l>p[lst].r){
            res++;
            lst=i;
        }
    cout<<res<<"\n";
    return 0;
}