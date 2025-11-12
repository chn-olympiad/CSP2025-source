#include<bits/stdc++.h>
using namespace std;
int n,m,zd,ai=0,zai=0,cs1=0,cs2=0,cs3=0;
int xh[20005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>xh[0];
            for(int z=1;z<3;z++)
            {
                cin>>xh[z];
                ai=max(xh[z],xh[z-1]);
            }
            if(ai==xh[0])
            {
                cs1++;
                if(cs1>=n/2)
                {
                    ai=max(xh[1],xh[2]);
                }
            }
            if(ai==xh[1])
            {
                cs2++;
                if(cs2>=n/2)
                {
                    ai=max(xh[2],xh[0]);
                }
            }
            if(ai==xh[2])
            {
                cs3++;
                if(cs3>=n/2)
                {
                    ai=max(xh[0],xh[1]);
                }
            }
            zai=zai+ai;
        }
        cout<<zai;
        zai=0;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
