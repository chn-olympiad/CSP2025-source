#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t[500005],f[500005];
struct node{
    int l,r;
}s[1000005];
bool cmp(node x,node y){
    return x.r<y.r;
}
int k;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    bool A=1,B=1;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]^t[i];
    }
    int c=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((f[j]^f[i-1])==k){
                s[++c].l=i,s[c].r=j;
            }
        }
    }
    sort(s+1,s+c+1,cmp);
    int r=0,cnt=0;
    for(int i=1;i<=c;i++){
        if(r<s[i].l){
            r=s[i].r;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
