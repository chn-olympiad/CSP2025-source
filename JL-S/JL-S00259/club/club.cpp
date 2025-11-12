#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,cnt=0;
    cin>>t>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(n/j<=n/2)
            {
                cnt+=t*n;
            }
            else
            {
                return 0;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
