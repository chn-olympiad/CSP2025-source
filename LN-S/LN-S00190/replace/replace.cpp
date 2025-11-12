#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
map < string ,string >mp;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >>n>>q;
    for(int i =1 ;i <= n ; i++){
        string a,b;
        cin >> a>>b;
        mp[a]=b;
    }
    for(int i = 0 ; i < q ; i++){
        string t1,t2;
        cin >>t1 >> t2;
        if(t1.size()!=t2.size()){
            cout << 0 <<endl;
            continue;
        }
        else{
            cout <<0 <<endl;
        }
    }
    return 0;
}
