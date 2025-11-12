#include<bits/stdc++.h>
using namespace std;
int t;
int a[10005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int e=0,g=0,h=0,y=0,p=0,x=0,gu=0,ab=0;
    int q,o,u,s;
    for(int i=t;i>0;i--)
    {
        int n;
        cin>>n;
        for(int j=n;j>0;j--)
        {
            for(int k=1;k<=3;k++)
            {
                cin>>a[k];
                s=1;
                if(a[s]>=a[s+1]&&a[s]>=a[s+2]&&g==0)
                {
                    if(h!=0&&a[s+1]>=a[s]&&a[s+1]>=a[s+2])
                    {
                        h=0;
                    }
                    if(y!=0&&a[s]<=a[s+2]&&a[s+1]<=a[s+2])
                    {
                        y=0;
                    }
                    e+=a[s];
                    g++;
                    if(p!=0)
                    {
                        e=e-q;
                    }
                    else{
                        q=a[s];
                        p++;
                    }

                    cout<<e<<endl;
                }
if(a[s]>=a[s+1]&&a[s]>=a[s+2]&&g>=1)
                {
                    if(h!=0&&a[s+1]>=a[s]&&a[s+1]>=a[s+2])
                    {
                        h=0;
                    }
                    if(y!=0&&a[s]<=a[s+2]&&a[s+1]<=a[s+2])
                    {
                        y=0;
                    }
                    e+=a[s];
                    g++;
                    if(p!=0)
                    {
                        e=e-q;
                    }
                    else{
                        q=a[s];
                        p++;
                    }

                    cout<<e<<endl;
                }

                else if(a[s+1]>=a[s]&&a[s+1]>=a[s+2]&&h==0)
                {
                      if(g==1&&a[s]>=a[s+2]&&a[s]>=a[s+1])
                    {
                        e+=a[s];
                        cout<<e;
                    }
                    if(y!=0&&a[s]<=a[s+2]&&a[s+1]<=a[s+2])
                    {
                        y=0;
                    }
                    e+=a[s+1];
                    h++;
                    if(x!=0)
                    {
                        e=e-o;
                    }
                    else{
                        o=a[s+1];
                        x++;
                    }

                    cout<<e<<endl;
                }

                else if(a[s+2]>=a[s]&&a[s+2]>=a[s+1]&&y==0)
                {
                    if(h!=0&&a[s+1]>=a[s]&&a[s+1]>=a[s+2])
                    {
                        h=0;
                    }
                    if(g==1&&a[s]>=a[s+2]&&a[s+1]<=a[s])
                    {
                        cout<<e;
                        e+=a[s];
                    }
                    e+=a[s+2];
                    y++;
                    if(gu!=0)
                    {
                        e=e-u;
                    }
                    else{
                        u=a[s+2];
                        gu++;
                    }
                    cout<<e<<endl;
                }

                else{
                    e+=0;
                }
                if(k==0)
                {
                    k=3;
                }
            }
            s+=3;
            p=0;x=0;gu=0;
        }
        g=0;
        h=0;
        y=0;
        if(i==0)
        {
            return 0;
        }
    }
    return 0;
}
