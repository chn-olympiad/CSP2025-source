#include <iostream>
using namespace std;
int z,x,c,u[10010],v[10010],w[10010],d[10010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>z>>x>>c;
    if(c==0)
    {
        for(int i=0;i<x;i++)
        {
            cin>>u[i]>>v[i]>>w[i];
        }
        d[u[0]]=d[v[0]]=1;
        int p=w[0];
        for(int j=1;j<=z;j++)
        {
            if(d[j]==1)continue;
            for(int i=1;i<x;i++)
            {
                if(d[u[i]]==1&&v[i]==j)
                {
                    d[j]=1;
                    p+=w[i];
                    goto out;
                }
            }
            out:;
        }
        cout<<p;
        return 0;
    }
    cout<<0;
    return 0;
}
