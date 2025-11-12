#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
long long k,a[500005],sum[500005];
struct node{
    int l,r;
}f[5000005];
bool cmp(node a,node b){
    if(a.r!=b.r) return a.r<b.r;
    return a.l>b.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=(sum[i-1]^a[i]);
    }
    int r=1;
    for(int l=1;l<=n;l++){
        while(r<n&&(sum[r]^sum[l-1])!=k){
            r++;
        }
        while(r<=n&&(sum[r]^sum[l-1])==k){
            f[++cnt]=node{l,r};
            //cout<<f[cnt].l<<" "<<f[cnt].r<<endl;
            r++;
        }
        r=l+1;
    }
    //cout<<cnt<<endl;
    if(cnt>0) ans=1;
    sort(f+1,f+1+cnt,cmp);
    int R=f[1].r;
    for(int i=2;i<=cnt;i++){
        if(f[i].l>R){
            ans++;
            R=f[i].r;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
