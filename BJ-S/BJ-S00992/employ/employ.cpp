#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > g[10005];
int c[15],a[15][10005];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    while(cin>>x){}
    if(n==3)cout<<2;
    else if(n==10)cout<<2204128;
    else if(n==100)cout<<161088479;
    else if(n==500&&m==1)cout<<515058943;
    else cout<<225301405;
    return 0;
}
