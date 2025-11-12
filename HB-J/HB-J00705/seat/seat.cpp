#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    vector<int> a;
    int m,n;
    cin>>n>>m;
    int num;
    for(int i=1;i<=n*m;i++)
    {
        cin>>num;
        a.push_back(num);
    }
    int mark=a[0];
    sort(a.begin(),a.end());
    int cnt=n*m-1;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[cnt]==mark)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt--;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                if(a[cnt]==mark)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt--;
            }
        }

    }
    return 0;
}
