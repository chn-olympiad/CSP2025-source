#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
int n,k,ans=0,t=0,a[N],s[1005][1005];
struct node{
    int l,r;
};
node b[N];
bool cmp(node x,node y){
    if(x.r==y.r) return x.l<y.l;
    else return x.r<y.r;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            s[i][j]=s[i][j-1]^a[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(s[i][j]==k){
                b[++t].l=i,b[t].r=j;
            }
        }
    }
    sort(b+1,b+t+1,cmp);
    int cnt_r=0;
    for(int i=1;i<=t;i++){
        if(b[i].l>cnt_r){
            ans++;
            cnt_r=b[i].r;
        }
    }
    cout<<ans;
    return 0;
}
