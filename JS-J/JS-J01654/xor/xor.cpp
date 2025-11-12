#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e5+5;
ll a[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=-INT_MAX;
    for(int i=1;i<=n;i++){
        int cun=0,cnt=0;
        int j=i;
        for(;j<=n;j++){
            if(a[j]==k){
                if(cun!=0) cun=0;
                cnt++;
                continue;
            }
            else if(cun==0) cun=a[j];
            else if(cun!=0) cun^=a[j];
            if(cun==k){
                cnt++;
                cun=0;
                continue;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
