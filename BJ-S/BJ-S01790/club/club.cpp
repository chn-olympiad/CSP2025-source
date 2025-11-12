#include <bits/stdc++.h>
using namespace std;
int t,n[10005],a[3],b[3],c[3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>t;
    for(int i=0;i<t;i++)
    {
        cin >>n[i];
        int sabc=0;
        int sabcd1=0,sabcd2=0,sabcd3=0;
        for(int j=0;j<n[i];j++)
        {
            cin>>a[j]>>b[j]>>c[j];
            if((a[j]>b[j])&&(a[j]>c[j]))
            {
                if(n[i]/2==sabcd1)
                {
                    if(b[j]>c[j])
                    {
                        sabcd2+=1;
                        sabc+=b[j];
                    }
                    else
                    {
                        sabcd3+=1;
                        sabc+=c[j];
                    }
                }
               else
               {
                   sabcd1+=1;
                   sabc+=a[j];
               }
            }
            else if((b[j]>c[j])&&(b[j]>a[j]))
            {
                if(n[i]/2==sabcd2)
                {
                    if(a[j]>c[j])
                    {
                        sabcd1+=1;
                        sabc+=a[j];
                    }
                    else
                    {
                        sabcd3+=1;
                        sabc+=c[j];
                    }
                }
               else
               {
                   sabcd2+=1;
                   sabc+=b[j];
               }
            }
            else
            {
                if(n[i]/2==sabcd3)
                {
                    if(b[j]>a[j])
                    {
                        sabcd2+=1;
                        sabc+=b[j];
                    }
                    else
                    {
                        sabcd1+=1;
                        sabc+=a[j];
                    }
                }
                else
               {
                   sabcd3+=1;
                   sabc+=c[j];
               }
            }
        }
        cout <<sabc<<endl;
    }
    return 0;
}
