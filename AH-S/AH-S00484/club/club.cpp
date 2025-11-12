#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,i,a2=0;
    int j,x,da;
    int jishu[5];
    int gw[3]={};
    for(x=0;x<5;x++) jishu[x]=-1;
    cin>>t;
    int n=0,zds=-1;
    int a[500000][3];
    for(i=0;i<500000;i++)
    {
        for(j=0;j<3;j++) 
        {
            a[i][j]=-1;
        }
    }
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(x=0;x<n;x++)
        {
            for(j=0;j<3;j++) 
            {
                cin>>a[x][j];
            }
        }
        for(x=0;x<n;x++)
        {
            for(j=0;j<3;j++)
            {
                if(a[x][j]>zds) 
                {
                    zds=a[x][j];
                    a2=j;
                }
            }
            gw[a2]++;
            for(da=0;da<3;da++)
            {
                if(gw[da]>n/2)
                {
                        if(gw[da+1]>n/2) 
                        {
                            jishu[i]+=a[x][2];
                            goto aans;
                        }
                        else 
                        {
                            jishu[i]+=a[x][1];
                            goto aans;
                        }
                }
            }
            jishu[i]+=zds;
            aans:
        }
        
    }
    for(x=0;jishu[x]!=-1;x++) 
    {
        cout<<jishu[x];
        if(jishu[x+1]==-1) break;
        else cout<<endl;
    }
    return 0;
}