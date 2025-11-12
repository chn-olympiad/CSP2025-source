#include <bits/stdc++.h>
using namespace std;
long long a[500005],k,b[500005];
struct st{
int l,r;}q[500005];
int n,p=0,ans=0,now=0;
bool cmp(st a,st b){
return a.r<b.r;}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=(a[i-1]^a[i]);
        b[i]=(a[i]^k);

    }
    for(int i=0;i<=n;i++){
        for(int j=1+i;j<=n;j++){
            if(a[i]==b[j]){
                q[++p].l=i+1;
                q[p].r=j;
            }
        }
    }
    sort(q+1,q+1+p,cmp);
    for(int i=1;i<=p;i++){


        if(now<q[i].l){
            ans++;
            now=q[i].r;
    }
    }
    cout<<ans;
}
