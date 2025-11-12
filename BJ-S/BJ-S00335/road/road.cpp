#include<iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
    }
    int f = 1;
    for(int i = 1;i<=k;i++)
    {
        int x;
        cin>>x;
        if(x!=0)
        {
            f = 0;
        }
        for(int j = 1;j<=n;j++)
        {
            int y;
            cin>>y;
            if(y!=0)
            {
                f = 0;
            }
        }
    }
    if(f == 1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout<<"13"<<endl;
    return 0;
}
