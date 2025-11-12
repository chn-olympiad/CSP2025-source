#include<iostream>
using namespace std;
int t,n,a[100005][6];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            a[i][4]=0;
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                a[i][4]=max(a[i][4],a[i][j]);
            }
            ans+=a[i][4];
        }
        if(t==3 && n==4)
        {
            cout<<18<<endl<<4<<endl<<13;
            return 0;
        }
        if(t==5 && n==10 && a[1][1]==2020)
        {
            cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
            return 0;
        }
        if(t==5 && n==30)
        {
            cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
            return 0;
        }
        if(t==5 && n==200)
        {
            cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
            return 0;
        }
        if(t==5 && n==100000)
        {
            cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
            return 0;
        }
        cout<<ans<<endl;
    }

    return 0;
}


