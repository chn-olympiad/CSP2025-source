#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n,k;
ll a[N];
bool vis[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    ll ans = 0;
    ll nmax = 0;
    ll flag = 0;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i] != 1)flag = 1;
        nmax = max(nmax,a[i]);
    }
    if(k == 0 && flag == 0){
        cout<<k/2;
        return 0;
    }
    if(nmax <= 1){
        if(k == 0){
            for(int i = 1;i <= n;i++){
                if(a[i] == 0){
                    ans++;
                }
                if(a[i] == 1 && a[i + 1] == 1){
                    ans++;
                    i++;
                }
            }
            cout<<ans;
            return 0;
        }
        if(k == 1){
            for(int i = 1;i <= n;i++){
                if(a[i] == 1){
                    ans++;
                }
            }
            cout<<ans;
            return 0;
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i] == k){
            vis[a[i]] = 1;
            ans++;
        }
    }
    ll tmp = 0;
    for(int i = 2;i <= n;i++){
        if(!vis[i])tmp = a[i - 1] ^ a[i];
        if(tmp == k){
            ans++;
        }
        for(int j = 1;j <= i;j++){
            vis[j] = 1;
        }
    }
    cout<<ans;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
