#include<bits/stdc++.h>
using namespace std;
int grid[15][15];
vector<int>v;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    int R=v.front();
    sort(v.begin(),v.end());

    int i=1,j=1;
    int f=1;
    while(1)
    {
        //cout<<i<<" "<<j<<"\n";
        if(i>n||j>m)
            break;
        grid[i][j]=v.back();
        v.pop_back();
        if(f&1)
        {
            if(i+1<=n)
                i++;
            else if(i+1>n)
            {j++;
                f=(f+1)%2;
            }

        }
        else
        {
            if(i-1>=1)
                i--;
            else
            {j++;
                f=(f+1)%2;
            }

        }

    }
    int ir,ic;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
             //cout << grid[i][j]<<" ";
            if(grid[i][j]==R)
            {
                ir=i;
                ic=j;
                break;
            }
        }
        //cout<<"\n";
    }
    cout<<ic<<" "<<ir;
    return 0;
}
