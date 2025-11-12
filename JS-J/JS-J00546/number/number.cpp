#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
string s;
int c[15];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fin("number.in");fout("number.out");
    cin>>s;
    for(char i:s){
        if(i>='0'&&i<='9') c[i-'0']++;
    }
    for(int i=9;i>=0;i--){
        rep(j,1,c[i]) cout<<i;
    }


    return 0;
}
//running limit time 3e8
