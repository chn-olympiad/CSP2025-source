#include <bits/stdc++.h>
using namespace std;
int n,m,c[5000];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)cin>>c[i];
    bool bo=1;
    for(int i=0;i<n;i++)bo&=(s[i]-'0');
    if(bo){cout<<0;return 0;}
}
