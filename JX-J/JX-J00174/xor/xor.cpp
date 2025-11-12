#include<bits/stdc++.h>
using namespace std;
int n,k,l,l1,a[500005],b[500005],ans=1,t=1,y;
struct intl{
    int l;
    int r;
}g[500005];
bool e(intl a,intl b){
    return a.l<b.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            l++;
        }
        if(a[i]==0){
            l1++;
        }
        b[i]=a[i];
        if(i!=0)b[i]^=b[i-1];
    }
    if(l==n&&k==0){
        cout<<n/2;
        return 0;
    }
    if(l+l1==n){
        if(k==0){
            cout<<l/2;
        }
        else{
            cout<<l;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if((b[i]^b[j-1])==k){
                g[t].l=j;
                g[t].r=i;
                t++;
            }
        }
    }
    t--;
    sort(g+1,g+t+1,e);
    y=g[1].r;
    for(int i=2;i<=t;i++){
        if(y<g[i].l){
            ans++;
            y=g[i].r;
        }
    }
    cout<<ans;
    return 0;
}

