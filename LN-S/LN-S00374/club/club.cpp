#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int s[100005][4][4];
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
            cin>>s[j][1][0]>>s[j][2][0]>>s[j][3][0];
        }
        int h=n/2;
        int ant=0;
        for(int j=1;j<=n;j++)
        {
            int flag[4]={0,0,0,0};

            if(flag[1]==h)
            {
                int c=ant+max(s[j][2][0],s[j][3][0]);
                int d;
                int l=0;
                int tong[205];
                memset(tong,0,sizeof(tong));
                for(int k=1;k<=n;k++)
                {
                    if(s[k][1][1]!=0)
                    {
                        l=max(l,max(s[k][2][0],s[k][3][0]));
                        if(l<s[k][2][0])
                        {
                            tong[k]=2;
                        }
                        if(l<s[k][3][0])
                        {
                            tong[k]=3;
                        }
                    }
                }
                int sum;
                for(int k=n;k>=1;k--)
                {
                    if(tong[k]=2)
                    {
                        d=ant+s[k][2][0]+s[j][1][0]-s[k][1][1];
                        sum=k;
                        k=0;
                    }
                    if(tong[k]=3)
                    {
                        d=ant+s[k][3][0]+s[j][1][0]-s[k][1][1];
                        sum=k;
                        k=0;
                    }
                }
                if(c>=d)
                {
                    ant=c;
                    if(max(s[j][2][0],s[j][3][0])==s[j][2][0])
                    {
                        s[j][2][2]=s[j][2][0];
                        s[j][2][0]=0;
                    }
                    else
                    {
                        s[j][3][3]=s[j][3][0];
                        s[j][3][0]=0;
                    }
                }
                else
                {
                    s[j][1][1]=s[j][1][0];
                    s[j][1][0]=0;
                    if(tong[sum]==2)
                    {
                        s[sum][2][1]=s[sum][2][0];
                        s[sum][2][0]=0;
                        s[sum][1][0]=s[sum][1][1];
                        s[sum][1][1]=0;
                    }
                    else
                    {
                        s[sum][3][1]=s[sum][3][0];
                        s[sum][3][0]=0;
                        s[sum][1][0]=s[sum][1][1];
                        s[sum][1][1]=0;
                    }
                    ant=d;
                }
            }
            if(flag[2]==h)
            {
                int c=ant+max(s[j][1][0],s[j][3][0]);
                int d;
                int l=0;
                int tong[205];
                memset(tong,0,sizeof(tong));
                for(int k=1;k<=n;k++)
                {
                    if(s[k][2][2]!=0)
                    {
                        l=max(l,max(s[k][1][0],s[k][3][0]));
                        if(l<s[k][1][0])
                        {
                            tong[k]=1;
                        }
                        if(l<s[k][3][0])
                        {
                            tong[k]=3;
                        }
                    }
                }
                int sum;
                for(int k=n;k>=1;k--)
                {
                    if(tong[k]=1)
                    {
                        d=ant+s[k][1][0]+s[j][2][0]-s[k][2][2];
                        sum=k;
                        k=0;
                    }
                    if(tong[k]=3)
                    {
                        d=ant+s[k][3][0]+s[j][2][0]-s[k][2][2];
                        sum=k;
                        k=0;
                    }
                }
                if(c>=d)
                {
                    ant=c;
                    if(max(s[j][1][0],s[j][3][0])==s[j][1][0])
                    {
                        s[j][1][1]=s[j][1][0];
                        s[j][1][0]=0;
                    }
                    else
                    {
                        s[j][3][3]=s[j][3][0];
                        s[j][3][0]=0;
                    }
                }
                else
                {
                    s[j][2][2]=s[j][2][0];
                    s[j][2][0]=0;
                    if(tong[sum]==2)
                    {
                        s[sum][3][3]=s[sum][3][0];
                        s[sum][3][0]=0;
                        s[sum][1][0]=s[sum][1][1];
                        s[sum][1][1]=0;
                    }
                    else
                    {
                        s[sum][3][1]=s[sum][3][0];
                        s[sum][3][0]=0;
                        s[sum][1][0]=s[sum][1][1];
                        s[sum][1][1]=0;
                    }
                    ant=d;
                }
            }
            if(flag[3]==h)
            {
                int c=ant+max(s[j][1][0],s[j][2][0]);
                int d;
                int l=0;
                int tong[205];
                memset(tong,0,sizeof(tong));
                for(int k=1;k<=n;k++)
                {
                    if(s[k][3][3]!=0)
                    {
                        l=max(l,max(s[k][2][0],s[k][1][0]));
                        if(l<s[k][2][0])
                        {
                            tong[k]=2;
                        }
                        if(l<s[k][1][0])
                        {
                            tong[k]=1;
                        }
                    }
                }
                int sum;
                for(int k=n;k>=1;k--)
                {
                    if(tong[k]=2)
                    {
                        d=ant+s[k][2][0]+s[j][3][0]-s[k][3][3];
                        sum=k;
                        k=0;
                    }
                    if(tong[k]=1)
                    {
                        d=ant+s[k][3][0]+s[j][1][0]-s[k][3][3];
                        sum=k;
                        k=0;
                    }
                }
                if(c>=d)
                {
                    ant=c;
                    if(max(s[j][2][0],s[j][1][0])==s[j][2][0])
                    {
                        s[j][2][2]=s[j][2][0];
                        s[j][2][0]=0;
                    }
                    else
                    {
                        s[j][1][1]=s[j][1][0];
                        s[j][1][0]=0;
                    }
                }
                else
                {
                    s[j][1][1]=s[j][1][0];
                    s[j][1][0]=0;
                    if(tong[sum]==2)
                    {
                        s[sum][2][2]=s[sum][2][0];
                        s[sum][2][0]=0;
                        s[sum][3][0]=s[sum][3][3];
                        s[sum][3][3]=0;
                    }
                    else
                    {
                        s[sum][1][1]=s[sum][1][0];
                        s[sum][1][0]=0;
                        s[sum][3][0]=s[sum][3][3];
                        s[sum][3][3]=0;
                    }
                    ant=d;
                }
            }
            else
            {
                /*
                int b;
                b=*/
                ant+=max(max(s[j][1][0],s[j][2][0]),s[j][3][0]);
                if(max(max(s[j][1][0],s[j][2][0]),s[j][3][0])==s[j][1][0])
                {
                    flag[1]++;
                    s[j][1][1]=s[j][1][0];
                    s[j][1][0]=0;
                }
                else if(max(max(s[j][1][0],s[j][2][0]),s[j][3][0])==s[j][2][0])
                {
                    flag[2]++;
                    s[j][2][1]=s[j][2][0];
                    s[j][2][0]=0;

                }
                else
                {
                    flag[3]++;
                    s[j][3][1]=s[j][3][0];
                    s[j][3][0]=0;

                }
            }

        }
        cout<<ant<<endl;
    }
    return 0;
}
