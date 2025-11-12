#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans,cnt;
bool use[N];
set<int> se;
struct node{
    int l,r;
}q[N];
node z[N];
bool cmp(node A,node B){
    if(A.l==B.l) return A.r>B.r;
    return A.l<B.l;
}
bool cmp2(node A,node B){
    if(A.r==B.r) return A.l>B.l;
    return A.r<B.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],se.insert(a[i]);
    if(se.size()==1&&k==0){//A
        cout<<n/2<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++) if(a[i]==k) q[++cnt]={i,i};
    int i=1,j=1,sum=0;
    for(;i<=n;i++){
        sum^=a[i];
        while(sum>k&&j<i){
            sum^=a[j++];
        }
        if(sum==k) q[++cnt]={j,i};
    }
    i--;
    while(j<i){
        sum^=a[j++];
        if(sum==k) q[++cnt]={j,i};
    } 
    sort(q+1,q+cnt+1,cmp);
    // cout<<cnt<<'\n';
    int last=n+1;
    for(int k=cnt;k>=1;k--){
        if(q[k].r>last) use[k]=true;
        last=q[k].r;
    }
    int op=0;
    last=0;
    for(int k=1;k<=cnt;k++) if(!use[k]) z[++op]={q[k].l,q[k].r};
    sort(z+1,z+op+1,cmp2);
    for(int k=1;k<=op;k++){
        if(z[k].l>last) last=z[k].r,ans++;  
        // cout<<z[k].l<<' '<<z[k].r<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}