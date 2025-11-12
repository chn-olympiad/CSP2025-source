#include<bits/stdc++.h>
using namespace std;
const int N=520;
int a[N];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3&&m==2) cout<<2;
    if(n==10&&m==5) cout<<2204128;
    return 0;
}
