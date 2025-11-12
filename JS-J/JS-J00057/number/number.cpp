#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define repr(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define pb push_back
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> v;
    rep(i,0,s.size()-1){
        if('0'<=s[i]&&s[i]<='9'){
            v.pb(s[i]-'0');
        }
    }
    //rep(i,0,v.size()-1)cout<<v[i]<<" ";cout<<endl;
    sort(v.begin(),v.end());
    //rep(i,0,v.size()-1)cout<<v[i]<<" ";cout<<endl;
    repr(i,v.size()-1,0){
        cout<<v[i];
    }
    cout<<endl;

    return 0;
}
