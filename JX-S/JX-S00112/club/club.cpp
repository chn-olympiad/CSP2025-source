#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005][4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0;
        int b[4]={0};
        for(int i=0;i<n;i++)
        {
                cin>>a[i][0]>>a[i][1]>>a[i][2];
                int b1=max(a[i][0],max(a[i][1],a[i][2]));
                int b2=min(a[i][0],min(a[i][1],a[i][2]));
                int b3=a[i][0]+a[i][1]+a[i][2]-b1-b2;
                int c=n/2;
                if(a[i][0]==b1)
                {
                    if(b[0]<c)
                    {
                        sum+=b1;
                        b[0]++;
                    }
                    else
                    {
                        if(a[i][1]==b3)
                        {
                            if(b[1]<c)
                            {
                                sum+=b3;
                                b[1]++;
                            }
                            else if(b[2]<c)
                            {
                                sum+=b2;
                                b[2]++;
                            }
                        }
                        else if(a[i][2]==b3)
                        {
                            if(b[2]<c)
                            {
                                sum+=b3;
                                b[2]++;
                            }
                            else if(b[1]<c)
                            {
                                sum+=b2;
                                b[1]++;
                            }
                        }
                    }
                }
                if(a[i][1]==b1)
                {
                    if(b[1]<c)
                    {
                        sum+=b1;
                        b[1]++;
                    }
                    else
                    {
                        if(a[i][2]==b3)
                        {
                            if(b[2]<c)
                            {
                                sum+=b3;
                                b[2]++;
                            }
                            else if(b[0]<c)
                            {
                                sum+=b2;
                                b[0]++;
                            }
                        }
                        else if(a[i][0]==b3)
                        {
                            if(b[0]<c)
                            {
                                sum+=b3;
                                b[0]++;
                            }
                            else if(b[2]<c)
                            {
                                sum+=b2;
                                b[2]++;
                            }
                        }
                    }
                }
                if(a[i][2]==b1)
                {
                    if(b[2]<c)
                    {
                        sum+=b1;
                        b[2]++;
                    }
                    else
                    {
                        if(a[i][0]==b3)
                        {
                            if(b[0]<c)
                            {
                                sum+=b3;
                                b[0]++;
                            }
                            else if(b[1]<c)
                            {
                                sum+=b2;
                                b[1]++;
                            }
                        }
                        else if(a[i][1]==b3)
                        {
                            if(b[1]<c)
                            {
                                sum+=b3;
                                b[1]++;
                            }
                            else if(b[0]<c)
                            {
                                sum+=b2;
                                b[0]++;
                            }
                        }
                    }
                }
        }
        cout<<sum<<endl;
    }
    return 0;
}
