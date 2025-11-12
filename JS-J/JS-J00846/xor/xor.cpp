#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int lt,rt;
}jr[500010];
int n,k,a[500010],ans=1,cnt;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int dp=i;
        for(int j=i;j<=n;j++){
            if(dp==k){
                bool f=false;
                for(int kq=1;kq<=cnt;kq++){
                    if(i>=jr[kq].lt||i<=jr[kq].rt&&j>=jr[kq].lt&&i<=jr[kq].lt){
                        f=true;
                        break;
                    }
                }
                if(!f) ans++;
                jr[++cnt].lt=i,jr[cnt].rt=j;
            }
            dp^=a[i];
        }
    }
    cout<<ans;
    return 0;
}
