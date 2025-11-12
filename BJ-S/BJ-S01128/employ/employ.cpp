#include<bits/stdc++.h>
using namespace std;
int m,n,sbl=0,pl=0,cg=0;
int nd[10005];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>nd[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>nd[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=n;i++)
        {
            if(nd[i]==1&&sbl<nd[i])
            {
                cg++;
            }
            else
            {
                sbl++;
            }
        }
        if(cg>=m)
        {
            pl++;
        }
    }
    cout<<pl%998%353%244;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
