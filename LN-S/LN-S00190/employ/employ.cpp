#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[550],b[550],cnt=1,h;
string s;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >>m >>s;
    for(int i =1 ; i <= n ;i++){
        cin >> a[i];
        b[a[i]]++;
    }
    if(m == n){
        for(int i = 0 ;i < s.size() ; i++){
            if(s[i]=='0'){
                cout << 0;
                return 0;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            cnt*=i;
            cnt%=998244353;
        }
        cout << cnt;
        return 0;
    }
    bool op=1;
    for(int i =0 ;i < s.size() ; i++){
        if(s[i]== '0'){
            op=0;
        }
        else{
            h++;
        }
    }
    if(op){
        for(int i = 1 ; i <= n ; i++){
            cnt*=i;
            cnt%=998244353;
        }
        cout << cnt;
        return 0;
    }
    cout <<0;
    return 0;
}
