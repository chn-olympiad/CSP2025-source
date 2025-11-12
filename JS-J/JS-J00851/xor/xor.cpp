#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
int s[1005][1005];

struct xd{
    int l;
    int r;
}xds[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int len = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            s[i][j] = s[i][j-1] ^ a[j];
            if(s[i][j]==k){
                xds[++len].l = i;
                xds[len].r = j;
            }
        }
    }
    int ans = 1;
    int nl=xds[1].l,nr=xds[1].r;
    for(int i=2;i<=len;i++){
        if(xds[i].l<=nr){
            if(xds[i].r<nr){
                nl = xds[i].l;
                    nr = xds[i].r;
                    continue;
            }
            continue;
        }
        nl = xds[i].l;
        nr = xds[i].r;
        ans++;
    }
    cout<<ans;
    return 0;
}
