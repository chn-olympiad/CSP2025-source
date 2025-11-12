#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,aa,yh[500010],tot,ans;
struct uct{
    LL l,r;
}a[200010];
bool cmp(const uct &x,const uct &y){
    return x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(LL i=1;i<=n;i++){
        cin>>aa;
        if(i==1){
            yh[i]=aa;
        }
        else{
            yh[i]=(yh[i-1]^aa);
        }
    }
    for(LL i=1;i<=n;i++){
        for(LL j=i;j<=n;j++){
            if(i==1){
                if(yh[j]==k){
                    a[++tot].l=i,a[tot].r=j;
                }
            }
            else{
                if((yh[j]^yh[i-1])==k){
                    a[++tot].l=i,a[tot].r=j;
                }
            }
        }
    }
    sort(a+1,a+tot+1,cmp);
    for(LL i=1;i<=tot;i++){
        if(a[i].r>=a[i+1].l){
            a[i+1].l=9999999,a[i+1].r=-9999999;
        }
    }
    for(LL i=1;i<=tot;i++){
        if(a[i].l!=9999999&&a[i].r!=-9999999){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
