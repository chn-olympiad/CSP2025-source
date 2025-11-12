#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int N = 5e3;
int n;
int a[N];
ll ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        cout<<(n-1)%MOD*(n-2)/2%MOD;
    }
    for(int i=3;i<=n;i++){
        vector<int>v(i+1);
        for(int j=1;j<=i;j++){
            v[j]=j;
        }
        while(v[i]<=n){
            ll h=0;
            int maxn=0
            for(auto l:v){
                h+=a[l];
                maxn=max(maxn,a[l]);
            }
            if(h>maxn*2){
                ans++;
            }
            v[i]++;
            int p=i;
            while(v[p]==p){
                p--;
            }
            a[p]++;
            for(int j=p+1;j<=i;j++){
                a[j]=a[j-1]+1;
            }
        }
        ans/=MOD;
    }
    cout<<ans;
    return 0;
}
