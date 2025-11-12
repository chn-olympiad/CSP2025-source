#include<bits/stdc++.h>
using namespace std ;
int n,q;
string s1,s2;
map<string,string> mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> s1 >> s2 ;
        mp[s1] = s2 ;
    }
    while(q -- ){
        int ans = 0 ;
        cin >> s1 >> s2 ;
        if(s1.size() != s2.size() ){
            cout << ans << endl ;
            continue ;
        }
        for(int i = 0 ; i < s1.size() ; i ++ ){//表示前i个一样
            if(s1.substr(0,i)!=s2.substr(0,i)) break;
            for(int j = s1.size()-1 ; j >= i ; j -- ){//表示后j个一样
                if(s1.substr(j+1,s1.size()- j - 1) != s2.substr(j+1,s1.size()- j - 1))
                    break;
                //当两端一样时，可以进行 下一步操作
                string a = s1.substr(i,j-i+1);
                string b = s2.substr(i,j-i+1);
                if(mp[a] == b) ans ++ ;
            }
        }
        cout << ans <<endl;
    }
    return 0 ;
}
// I LOVE HXT !
