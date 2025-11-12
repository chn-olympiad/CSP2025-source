#include<bits/stdc++.h>
using namespace std;
int n,d,ans=0;
struct ak
{
    int num,st,ed;
}a[500500];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i].num==d) ans++;
    }
    cout<<ans;
    return 0;
}
