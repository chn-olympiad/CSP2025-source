#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],max_num,cnt=0,ans1,ans2;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    max_num=a[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i][j]>max_num)
            {
                cnt++;
            }
        }
    }
    ans1=cnt/n;
    ans2=cnt%n;
    cout<<ans1<<" "<<ans2;
    return 0;
}

