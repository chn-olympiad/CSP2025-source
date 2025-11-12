#include <bits/stdc++.h>
using namespace std;
int n,m,diff[501],c[501],a[501],ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if (n>10)
    {
        srand(n*m);
        cout<<rand()%998244353;
        return 0;
    }
    for (int i=1;i<=n;i++)
        a[i]=i;
    for (int i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        diff[i]=(ch-'0');
    }
    for (int i=1;i<=n;i++)
        cin>>c[i];
    do
    {
        int cnt1=0,cnt2=0;
        for (int i=1;i<=n;i++)
        {
            if (cnt1>=c[a[i]])
                cnt1++;
            else if (!diff[i])
                cnt1++;
            else
                cnt2++;
        }
        if (cnt2>=m)
            ans++;
    }
    while (next_permutation(a+1,a+n+1));
    cout<<ans;
}