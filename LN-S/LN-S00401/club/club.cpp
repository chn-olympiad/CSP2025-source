#include<bits/stdc++.h>
using namespace std;
int a1[100001];
int a2[100001];
int a3[100001];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n;
    int N;
    int ans=0;
    int xiaxian;
    int c1;
    int c2;
    int c3;
    int u;
    int b1;
    int b2;
    int b3;
    int d=0;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        ans=0;
        c1=n;
        c2=n;
        c3=n;
        d=0;
        u=0;
        b1=-1;
        b2=-1;
        b3=-1;
        u=-1;
        for(int I=0;I<n;I++)
        {
            cin>>a1[I]>>a2[I]>>a3[I];
        }
        xiaxian=n/2;
        for(int y=n-1;y>=0;y--)
        {
            if(a1[y]>=a2[y] and a1[y]>=a3[y] and c1>xiaxian and b1!=y)
            {
                ans=ans+a1[y];
                c1=c1-1;
            }
            else if(a1[y]>=a2[y] and a1[y]>=a3[y] and c1<=xiaxian and b1!=y)
            {
                c1=c1+1;
                ans=ans-a1[y+1];
                b1=y;
                u=a1[y];
                a1[y]=a1[y+1];
                a1[y+1]=u;
                y=y+2;
                d=1;
            }
            else if(a1[y]>=a2[y] and a1[y]>=a3[y])
            {
                ans=ans-a1[y+1];
                ans=ans+max(a1[y+1],a1[y]);
                b1=-1;
                c1=c1-1;
            }
            else if(a2[y]>a1[y] and a2[y]>=a3[y] and c2>xiaxian and b2!=y)
            {
                ans=ans+a2[y];
                c2=c2-1;
            }
            else if(a2[y]>a1[y] and a2[y]>=a3[y] and c2<=xiaxian and b2!=y)
            {
                c2=c2+1;
                ans=ans-a2[y+1];
                u=a2[y+1];
                b2=y;
                a2[y]=a2[y+1];
                a2[y+1]=u;
                y=y+2;
                d=2;
            }
            else if(a2[y]>a1[y] and a2[y]>=a3[y])
            {
                ans=ans-a2[y+1];
                ans=ans+max(a2[y+1],a2[y]);
                b2=-1;
                c1=c1-1;
            }
            else if(a3[y]>a2[y] and a3[y]>a1[y] and c3>xiaxian and b3!=y)
            {
                ans=ans+a3[y];
                c3=c3-1;

            }
            else if(a3[y]>a2[y] and a3[y]>a1[y] and c3<=xiaxian and b3!=y)
            {
                c3=c3+1;
                ans=ans-a3[y+1];
                u=a3[y];
                b3=y;
                a3[y]=a3[y+1];
                a3[y+1]=u;
                y=y+2;
                d=3;
            }
            else if(a3[y]>a2[y] and a3[y]>a1[y])
            {
                ans=ans-a3[y+1];
                ans=ans+max(a3[y+1],a3[y]);
                b3=-1;
                c3=c3-1;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
