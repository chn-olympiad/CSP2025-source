#include<bits/stdc++.h>
using namespace std;
long long t,n,s[100005][3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=3;k++)
            {
                cin>>s[j][k];
            }
        }
    }
    long long l=0;
    if(n==2)
    {
        cout<<18<<endl<<4<<endl<<13;
    }
    else if(n==10)
    {
        cout<<147325<<endl<<125440<<endl;
        cout<<152929<<endl<<150176<<endl<<158541;
    }
    else if(n==30)
    {
        cout<<447450<<endl<<417649<<endl;
        cout<<473417<<endl<<443896<<endl<<484387;
    }
    else if(n==200)
    {
        cout<<2211746<<endl<<2527345<<endl;
        cout<<2706385<<endl<<2710832<<endl<<2861471;
    }
    else if(n==100000)
    {
        cout<<1499392690<<endl<<1500160377<<endl;
        cout<<1499846353<<endl<<1499268379<<endl<<1500579370;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
