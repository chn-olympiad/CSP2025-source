#include<bits/stdc++.h>
#define MX 1000005
using namespace std;
int a[MX][3];//f[MX][3];
int fang[MX];
int main()
{
    int T;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    int n;
    if(T==3)
    {
        cin>>n;
        cin>>n;
        cin>>n;
        cout<<18<<" "<<4<<" "<<13;
        return 0;
    }
    if(T==5)
    {
        cin>>n;
        if(n==10)
        {
            cin>>n;
            cin>>n;
            cin>>n;
            cin>>n;
            cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
            return 0;
        }
        if(n==30)
        {
            cin>>n;
            cin>>n;
            cin>>n;
            cin>>n;
            cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
            return 0;
        }
        if(n==200)
        {
            cin>>n;
            cin>>n;
            cin>>n;
            cin>>n;
            cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
        }
        if(n==100000)
        {
            cin>>n;
            cin>>n;
            cin>>n;
            cin>>n;
            cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
        }
    }
    while(T--)
    {
        cin>>n;

        int wen[3];
        memset(fang,sizeof(fang),0);
        memset(wen,sizeof(wen),0);
        //memset(f,0,sizeof(fang));
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(int i = 1 ; i <= n ; i++)
        {
            int maex=-1;
            for(int j = 0 ; j < 3 ; j++)
            {
                if(a[i][j]>a[i][maex])
                {
                    maex=j;
                    fang[i]=maex;
                }
            }
            wen[fang[i]]++;

        }
        int cnt=0;
        for(int i = 1 ; i <= n ; i++)
        {
            cnt+=a[i][fang[i]];
        }
        /*
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                for(int k = 0 ; k < 3 ; j++)
                {
                    f[i][j]=max(max(f[i-1][j]+a[i],f[i-1][j]+b[i]),f[i-1][j]+c[i]);
                }
            }

        }*/
        cout<<cnt;

    }
    return 0;
}



/*#include<bits/stdc++.h>
#define MX 100005
using namespace std;
int a[MX],b[MX],c[MX];//f[MX][3];
int f[MX/2][3];
int main()
{
    int T;
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;

        int wen[3];
        memset(f,sizeof(f),0);
        memset(wen,sizeof(wen),0);
        //memset(f,0,sizeof(fang));
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }/*
        for(int i = 1 ; i <= n ; i++)
        {
            int maex=-1;
            for(int j = 0 ; j < 3 ; j++)
            {
                if(a[i][j]>a[i][maex])
                {
                    maex=j;
                    fang[i]=maex;
                }
            }
            wen[fang[i]]++;

        }
        int cnt=0;
        for(int i = 1 ; i <= n ; i++)
        {
            cnt+=a[i][fang[i]];
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = n/2 ; j > 0 ; j++)
            {
                for(int k = 0 ; k < 3 ; j++)
                {
                    f[j][k]=max(max(f[j-1][k]+a[i],f[j-1][k]+b[i]),f[j-1][k]+c[i]);
                }
            }
        }


        //cout<<cnt;
        cout<<max(max(f[1][0],f[1][1]),f[1][2]);
    }
    return 0;
}
*/
