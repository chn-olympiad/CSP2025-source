#include<bits/stdc++.h>
using namespace std;
int f,n,pp,m=100000,pd=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(int h=1;h<=n;h++)
    {
        cin>>pp;
        int k[4]={0},g=0,js=0;
        int a[pp][4];
        int x[pp]={0},y[pp]={0},z[pp]={0};//
        int x1=0,y1=0,z1=0;
        for(int i=1;i<=pp;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
        for(int i=1;i<=pp;i++)
        {
            x[i]=a[i][1];
            y[i]=a[i][2];
            z[i]=a[i][3];
        }
        for(int i=1;i<=pp;i++)
        {
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
            {
                k[1]+=a[i][1];
                x1++;
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
            {
                k[2]+=a[i][2];
                y1++;
            }
            else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])//
            {
                k[3]+=a[i][3];
                z1++;
            }

        }
        //cout<<k[1]<<" "<<k[2]<<" "<<k[3];
        //cout<<" "<<pp/2;
        if(x1>pp/2)//
        {
            f=1;
            js=x1-pp/2;
            for(int i=1;i<=js;i++)
            {
                for(int q=1;q<=pp;q++)
                {
                    m=min(m,x[q]);
                    pd=q;
                }
                //cout<<m<<"ppp"<<endl;
                k[1]-=m;
                if(a[pd][2]>=a[pd][3])
                {
                    k[2]+=a[pd][2];
                    y1++;
                }
                else
                {
                    k[3]+=a[pd][3];
                    z1++;
                }
                x1--;
            }
        }
        else if(y1>pp/2)
        {
            js=y1-pp/2;
            for(int i=1;i<=js;i++)
            {
                for(int q=1;q<=pp;q++)
                {
                    m=min(m,y[q]);
                    pd=q;
                }
                //cout<<m<<"ppp"<<endl;
                k[2]-=m;
                if(a[pd][1]>=a[pd][3])
                {
                    k[1]+=a[pd][1];
                    x1++;
                }
                else
                {
                    k[3]+=a[pd][3];
                    z1++;
                }
                y1--;
            }
        }
        else if(z1>pp/2)
        {
            js=z1-pp/2;
            for(int i=1;i<=js;i++)
            {
                for(int q=1;q<=pp;q++)
                {
                    m=min(m,z[q]);
                    pd=q;
                }
                k[3]-=m;
                if(a[pd][1]>=a[pd][2])
                {
                    k[1]+=a[pd][1];
                    x1++;
                }
                else
                {
                    k[3]+=a[pd][2];
                    y1++;
                }
                z1--;
            }
        }
        cout<<k[1]+k[2]+k[3]<<endl;
    }
    return 0;
}
