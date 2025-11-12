#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,ans,p;
int a[500020];
struct node{
    int l,r;
}f[10000020];
bool cmp(node x,node y){
    if(x.r!=y.r)return x.r<y.r;
    else return x.l>y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool s1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)s1=0;
    }
    if(s1){
        int cnt0=0,cnt1=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                cnt0++;
            }else cnt1++;
        }
        if(k==0){
            cout<<cnt0;
        }else if(k==1){
            cout<<cnt1;
        }else{
            cout<<0;
        }
        return 0;
    }
    ans=0,p=0;
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=i;j<=n;j++){
            cnt^=a[j];
            if(cnt==k){
                f[++p]={i,j};
            }
        }
    }
    sort(f+1,f+1+p,cmp);
    int l=0;
    for(int i=1;i<=p;i++){
        if(f[i].l>l){
            l=f[i].r;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
