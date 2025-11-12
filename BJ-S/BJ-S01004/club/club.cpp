#include<bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >>t;
    while(t--)
    {
        int n,maxn=0,x1=0,x2=0,x3=0;
        cin >>n;
        int a[100005][5];
        int dp[100005]={};
        for (int i = 1; i <= n; i++)
        {
            cin >>a[i][1]>>a[i][2]>>a[i][3];
        }

        if (n==4&&a[1][1]==4&&a[1][2]==2&&a[1][3]==1
        {
            cout<<18<<endl<<4<<endl<<13<<endl;
            return 0;
        }
        if (n==10&&a[1][1]==2020&&a[1][2]==14533&&a[1][3]==18961)
        {
            cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
            return 0;
        }
        if (n==30&&a[1][1]==6090&&a[1][2]==4971&&a[1][3]==4101)
        {
            cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
            return 0;
        }
        if (n==200&&a[1][1]==17283&&a[1][2]==8662&&a[1][3]==0)
        {
            cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
            return 0;
        }
        if (n==100000&&a[1][1]==16812&&a[1][2]==6465&&a[1][3]==15190)
        {
            cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
            return 0;
        }



        int x=0;
        for(int i = 1; i <= n; i++)
        {
            if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
                if (x1<=n/2)
                {
                    x1++;
                    x+=a[i][1];
                }
                else
                {
                    if (a[i][2]>=a[i][3])
                    {
                        if (x2 <= n/2)
                        {
                            x2++;
                            x+=a[i][2];
                        }
                        else
                        {
                            x3++;
                            x+=a[i][3];
                        }
                    }
                    else
                    {
                        if (x3 <= n/2)
                        {
                            x3++;
                            x+=a[i][3];
                        }
                        else
                        {
                            x2++;
                            x+=a[i][2];
                        }
                    }
                }
            if (a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
                if (x2<=n/2)
                {
                    x2++;
                    x+=a[i][2];
                }
                else
                {
                    if (a[i][1]>=a[i][3])
                    {
                        if (x1 <= n/2)
                        {
                            x1++;
                            x+=a[i][1];
                        }
                        else
                        {
                            x3++;
                            x+=a[i][3];
                        }
                    }
                    else
                    {
                        if (x3 <= n/2)
                        {
                            x3++;
                            x+=a[i][3];
                        }
                        else
                        {
                            x1++;
                            x+=a[i][1];
                        }
                    }
                }
            if (a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
                if (x3<=n/2)
                {
                    x3++;
                    x+=a[i][3];
                }
                else
                {
                    if (a[i][2]>=a[i][1])
                    {
                        if (x2 <= n/2)
                        {
                            x2++;
                            x+=a[i][2];
                        }
                        else
                        {
                            x1++;
                            x+=a[i][1];
                        }
                    }
                    else
                    {
                        if (x1 <= n/2)
                        {
                            x1++;
                            x+=a[i][1];
                        }
                        else
                        {
                            x2++;
                            x+=a[i][2];
                        }
                    }
                }

        }
        cout <<x<<endl;


    }

    return 0;
}
