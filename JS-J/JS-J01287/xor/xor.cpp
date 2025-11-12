#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
int n,k;
int a[N],sum[N],h=1,R=0,ans1=0,ans=0;
struct node{
    int l;int r;
}b[N];
bool cmp(node a,node b){
    if(a.l==b.l)return a.r<b.r;
    else return a.l<b.l;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
               b[h].l=i;
               b[h++].r=j;
            }
        }
    }
    sort(b+1,b+h,cmp);
    for(int x=1;x<h;x++){
            ans1=0;
            R=0;
        for(int i=x;i<h;i++){
            if(b[i].l>R){
                ans1++;
                R=b[i].r;
            }
        }
        ans=max(ans1,ans);
    }

    cout<<ans;
    return 0;
}
