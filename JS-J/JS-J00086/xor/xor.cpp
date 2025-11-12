#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 11451;
int f[N],l,r;
bool flag[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    int n,k,ans=0;
    cin >> n >> k;
    l=1,r=1;
    for(int i = 1 ; i<= n ; i++){
        cin >> f[i];
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n ; j++){
                int s = f[i];
            for(int x = i+1 ; x <= j ; x++){
                s^=f[x];
                if(flag[x] == 1 || flag[i] == 1){
                    s = -1;
                    break;
                }
            }
            if(flag[i] == 1)s = -1;
            //cout << s << endl;
            if(s == k){

            ans++;
            for(int y = i ; y<= j ; y++)flag[y] = 1;
        }
    }
    }
    cout << ans << endl;
    return 0;
    }

