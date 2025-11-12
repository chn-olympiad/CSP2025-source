#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k[10001][10001];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);










    int n;
    int m;
    int s;
    int b;
    int g=0;
    cin>>n>>m;
    vector <int> a (n*m,0);
    cin>>s;
    a.push_back(s);
    for(int i=0; i<n*m-1; i++)
    {
        cin>>b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    for(int i=1; i<=m; i++)
    {
        if(i%2==1)
        {
            for(int j=1; j<=n; j++)
            {
                k[i][j]=a[g];
                g++;
                if(k[i][j]==s)
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
        else
        {
            for(int j=n; j!=0; j--)
            {
                k[i][j]=a[g];
                g++;
                if(k[i][j]==s)
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }

    }

return 0;
}

