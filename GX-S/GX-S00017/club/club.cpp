#include <iostream>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int t,ans=0;
long long n,f[100005][3],hyy[3],myq[3][100005];
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--)
    {
        ans=0;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>f[i][0]>>f[i][1]>>f[i][2];
            if (f[i][0]>f[i][1]&&f[i][0]>f[i][2])
            {
                hyy[0]++;
            }
            else if (f[i][0]>f[i][1]&&f[i][2]>f[i][0])
            {
                hyy[2]++;
            }
            else
            {
                hyy[1]++;
            }
        }
        for (int i=0;i<n;i++)
            ans+=max(max(f[i][0],f[i][1]),f[i][2]);
        cout<<ans<<endl;
    }
    return 0;
}

