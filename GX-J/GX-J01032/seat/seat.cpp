#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=0;j<m;j++)
        {
            if(a[i]>=a[i+1] || a[i]>=a[i-1])
            {

            }

        }
    }
    //小R not木;
    return 0;

}
