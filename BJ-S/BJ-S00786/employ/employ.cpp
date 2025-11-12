#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
ll c[1000001];
ll a[1000001];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n = 0,m = 0;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i = 1;i <= n;i++){
        cin>>c[i];
    }
    if(n <= 12){ //8pts
        ll ans = 0;
        for(int i = 1;i <= n;i++) a[i] = i;
        do{
            ll cnt = 0; //number of how does least people gone
            ll take_number = 0;
            for(int i = 1;i <= n;i++){
                if(cnt >= c[a[i]]){ //sile
                    cnt++;
                    continue;
                }
                else if(s[i - 1] == '0') //sile
                {
                    cnt++;
                    continue;
                }
                else if(s[i - 1] == '1'){
                    take_number++;
                }
            }

            if(take_number >= m) ans = (ans + 1) % mod;
        }while(next_permutation(a + 1,a + n + 1));
        cout<<ans<<endl;
    }
    return 0;
}
