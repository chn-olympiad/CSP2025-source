#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans1,ans2;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            ans1++;
        }else{
            ans2++;
        }
    }
    if(k==1)
    {
        cout<<ans2;
    }
    if(k==0)
    {
        cout<<ans1;
    }
    return 0;
}
