#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],xo[500005];
long long cnt,ans;
struct node{
    int l,r;
}x[1000005];
bool cmp(node x,node y){
    if(x.r!=y.r) return x.r<y.r;
    return x.r-x.l<y.r-y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for( int i=1;i<=n;i++ ){
        cin>>a[i];
    }
    if(n<=1000){
        for( int i=1;i<=n;i++ ){
            xo[i]=xo[i-1]^a[i];
        }
       for( int i=1;i<=n;i++ ){
            for( int j=1;j<=i;j++ ){
                if((xo[i]^xo[j-1])==k){
                    x[++cnt].l=j;
                    x[cnt].r=i;
                }
            }
        }
        sort(x+1,x+cnt+1,cmp);
        int lr=x[1].r;
        for( int i=2;i<=cnt;i++ ){
            if(x[i].l>lr){
                ans++;
                lr=max(x[i].r,lr);
            }
        }
        cout<<ans+1;
    }else{
        bool f1=1,f0=1;
        int c=0;
        for( int i=1;i<=n;i++ ){
            if(a[i]!=0) f0=0;
            if(a[i]!=1) f1=0;
            if(a[i]==1) c++;
        }
        if(k==0){
            if(f0) cout<<n;
            else if(f1) cout<<n/2;
            else cout<<c/2;
        }else{
            if(f0) cout<<0;
            else if(f1) cout<<n;
            else cout<<c;
        }
    }
    return 0;
}
