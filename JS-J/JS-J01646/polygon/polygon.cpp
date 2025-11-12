#include<bits/stdc++.h>
using namespace std;
int n,a[5000],maxn;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 0;i < n;i++) cin>>a[i];
    maxn=max(a[0],max(a[1],a[2]));
    if(a[0]+a[1]+a[2]>maxn) cout<<1;
    else cout<<0;
    return 0;
}
