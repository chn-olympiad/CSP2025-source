#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int t=0;
    cin>>t;

    int ans=0;
    for(int i=0;i<t;i++)
    {
        int te=0;
        cin>>te;
        if(te==1)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
