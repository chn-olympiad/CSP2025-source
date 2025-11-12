#include<bits/stdc++.h>
using namespace std;
#define int long long
#define r first
#define l second
int n,k,a[500005],cnt,ans,t;
pair<int,int> p[500005];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        cnt=0;
        for(int r=l;r<=n;r++){
            cnt=cnt^a[r];
            if(cnt==k){
                p[++t]={r,l};
                break;
            }
        }
    }
    if(t==0){
        cout<<0;
        return 0;
    }
    sort(p+1,p+t);
    int x=1,r=p[1].r;
    ans=1;
    for(int i=2;i<=t;i++){
        if(p[i].l>r){
            ++ans;
            r=p[i].r;
        }
    }
    cout<<ans;
    return 0;
}
