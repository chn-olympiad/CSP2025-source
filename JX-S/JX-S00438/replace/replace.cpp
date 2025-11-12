#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int q;
string s[N][3],t[3];
map<string,string> to;
signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    Cios;
    int m;
    cin>>m>>q;
    for (int i=1;i<=m;i++) {
        cin>>s[i][1]>>s[i][2];
        to[s[i][1]]=s[i][2];
    }
    while (q--) {
        cin>>t[1]>>t[2];
        int n=t[1].size();
        t[1]=" "+t[1];
        t[2]=" "+t[2];
        int begin=-1,end=-1;
        for (int i=1;i<=n;i++) {
            if (t[1][i]!=t[2][i]) {
                begin=i;
                break;
            }
        }
        for (int i=n;i>=1;i--) {
            if (t[1][i]!=t[2][i]) {
                end=i;
                break;
            }
        }
        int ans=0;
        for (int l=1;l<=begin;l++) {
            for (int r=n;r>=end;r--) {
                string t1to="";
                string t2to="";
                for (int i=l;i<-r;i++) t1to+=t[1][i];
                for (int i=l;i<=r;i++) t2to+=t[2][i];
                // cout<<l<<" "<<r<<"\n";
                // cout<<t1to<<" "<<to[t1to]<<"\n";
                if (to[t1to]==t2to) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
//g++ replace.cpp -o replace -O2 -std=c++14 -static
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/