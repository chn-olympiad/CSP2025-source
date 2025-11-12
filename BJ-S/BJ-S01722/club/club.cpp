#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int the=0;the<t;the++)
    {
        int n;
        cin>>n;
        int a[n][3],ch[n],cx=0,cy=0,cz=0,ans=0,ju[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i][0]>a[i][1])
            {
                if(a[i][0]>a[i][2])
                {
                    cx++;
                    ch[i]=0;
                    ans+=a[i][0];
                    ju[i]=a[i][0]-max(a[i][1],a[i][2]);
                }
                else
                {
                    cz++;
                    ch[i]=2;
                    ans+=a[i][2];
                    ju[i]=a[i][2]-max(a[i][1],a[i][0]);
                }
            }
            else
            {
                if(a[i][1]>a[i][2])
                {
                    cy++;
                    ch[i]=1;
                    ans+=a[i][1];
                    ju[i]=a[i][1]-max(a[i][0],a[i][2]);
                }
                else
                {
                    cz++;
                    ch[i]=2;
                    ans+=a[i][2];
                    ju[i]=a[i][2]-max(a[i][1],a[i][0]);
                }
            }
        }
/*
        cout<<ans<<"\n"<<cx<<" "<<cy<<" "<<cz<<" \n";
        for(int i=0;i<n;i++)
        {
            cout<<ju[i]<<" ";
        }
        cout<<"\n";
        */
        if(cx>n/2)
        {
            for(int i=0;i<cx-n/2;i++)
            {
                int mi=1e9+7,p=-1;
                for(int j=0;j<n;j++)
                {
                    if(ch[j]==0)
                    {
                        if(ju[j]<mi)
                        {
                            mi=ju[j];
                            p=j;
                        }
                    }
                }
                ans-=mi;
                ch[p]=-1;
            }
        }
        else if(cy>n/2)
        {
            for(int i=0;i<cy-n/2;i++)
            {
                int mi=1e9+7,p=-1;
                for(int j=0;j<n;j++)
                {
                    if(ch[j]==1)
                    {
                        if(ju[j]<mi)
                        {
                            mi=ju[j];
                            p=j;
                        }
                    }
                }
                ans-=mi;
                ch[p]=-1;
            }
        }
        else if(cz>n/2)
        {
            for(int i=0;i<cz-n/2;i++)
            {
                int mi=1e9+7,p=-1;
                for(int j=0;j<n;j++)
                {
                    if(ch[j]==2)
                    {
                        if(ju[j]<mi)
                        {
                            mi=ju[j];
                            p=j;
                        }
                    }
                }
                ans-=mi;
                ch[p]=-1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}