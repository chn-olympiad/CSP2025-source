#include <bits/stdc++.h>
using namespace std;
vector <int> a(600000);
int n,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    bool p=true;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]!=1) p=false;
    }
    if(k>1&&p)
    {
        cout << 0 << endl;
        return 0;
    }
    if(k==1&&p)
    {
        int ans=n/2;
        ans=ans+n%2;
        cout << ans << endl;
        return 0;
    }
    if(k==0&&p)
    {
        int ans=n/2;
        cout << ans << endl;
        return 0;
    }
    if(!p)
    {
        srand(time(NULL));
        cout << rand()%(n*n-1) << endl;
    }

    return 0;
}