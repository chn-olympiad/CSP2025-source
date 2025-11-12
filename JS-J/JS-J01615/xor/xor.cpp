#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int s=0,cnt=0;
    set<int> x;
    x.insert(0);

    for(int i=1;i<=n;i++)
    {
        s^=a[i];
        if(x.count(s^k))
        {
            cnt++;
            s=0;
            
            x.clear();
            x.insert(0);
        }
        else
            x.insert(s);
    }
    
    cout<<cnt<<'\n';

    return 0;
}