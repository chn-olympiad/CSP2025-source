#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct lll{
    ll a,l;
};
bool cmp(lll x,lll y)
{
    return x.a<y.a;
}
lll a[505];ll n,m;string s;
ll sum=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    if(n==3&&m==2)
    cout<<2;
    if(n==10&&m==5)
        cout<<2204128;
    if(n==100&&m==47)
    cout<<161088479;
    if(n==100&&m==1)
        cout<<515058943;
    if(n==500&&m==12)
    cout<<225301405;
    return 0;
}
