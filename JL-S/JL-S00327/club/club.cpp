#include <bits/stdc++.h>
using namespace std;

int t,n,a[5][10100],ans1,ans2,ans3,p1,p2,p3,k,q,s,x;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t ;
    for(int i=1;i<=t;i++)
    {
        ans1=0;
        ans2=0;
        ans3=0;
        p1=1;
        p2=1;
        p3=1;
        cin >> n;
        k=n/2;
        for(int j=1;j<=n;j++) cin >> a[1][j] >> a[2][j] >>a[3][j];
        for(int j=1;j<=n;j++)
        {
            s=0;
            if((a[2][j]==0)&&(a[3][j]==0))
            {
                q=a[1][1];
                x=1;
                for(int l=1;l<=n;l++){
                    if((q>a[1][l])&&(x!=l))
                    {
                        q=a[1][l];
                    }
                }
                if(q>=a[1][j])
                {
                    ans1+=a[1][j];
                    p1++;
                    ans1-=a[1][x]-max(a[2][x],a[3][x]);
                    a[1][x]=0;
                }
            }
            if(a[1][j]>=a[2][j])
            {
                if(a[1][j]>=a[3][j])
                {
                    if(p1<=k)
                    {
                        ans1+=a[1][j];
                        p1++;
                    }
                    else if(a[2][j]>=a[3][j])
                    {
                        ans2+=a[2][j];
                        p2++;
                    }
                    else
                    {
                        ans3+=a[3][j];
                        p3++;
                    }
                }
                else
                {
                    if(p3<=k)
                    {
                        ans3+=a[3][j];
                        p3++;
                    }
                    else
                    {
                        ans1+=a[1][j];
                        p1++;
                    }
                }
            }
            else
            {
                if(a[2][j]>=a[3][j])
                {
                    if(p2<=k)
                    {
                        ans2+=a[2][j];
                        p2++;
                    }
                    else
                    {
                        if(a[1][j]>=a[3][j])
                        {
                            ans1+=a[1][j];
                            p1++;
                        }
                        else
                        {
                            ans3+=a[3][j];
                            p3++;
                        }
                    }
                }
                else
                {
                   if(p3<=k)
                    {
                        ans3+=a[3][j];
                        p3++;
                    }
                    else
                    {
                        ans2+=a[2][j];
                        p2++;
                    }
                }
            a[1][j]=0;
            a[2][j]=0;
            a[3][j]=0;
            }
        }
        cout << ans1+ans2+ans3+s << endl;

    }
    return 0;
}
