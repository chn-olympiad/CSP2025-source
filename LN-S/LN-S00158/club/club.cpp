#include<bits/stdc++.h>
using namespace std;
struct n{
    int x,y;
}b[100010][10],fun[100010];
bool ui(n o,n p)
{
    if(o.x!=p.x)
    return o.x<p.x;
    return o.y<p.y;
}
bool iu(n o,n p)
{
    if(o.y!=p.y)
        return o.y<p.y;
    return o.x<p.x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int a;
        cin>>a;
        for(int i = 1;i<=a;i++)
        {
            for(int j = 1;j<=3;j++)
            {
                cin>>b[i][j].x;
                b[i][j].y=j;
            }
            sort(b[i]+1,b[i]+3+1,ui);
            fun[i].x=b[i][3].x-b[i][2].x;
            fun[i].y=b[i][3].y;
        }
        sort(fun+1,fun+a+1,iu);
        int fi= 0,se = 0,th = 0,ans = 0;
        for(int i = 1;i<=a;i++)
        {
            if(b[i][3].y==1)
                fi++;
            else if(b[i][3].y==2)
                se++;
            else
                th++;
        }
        if(fi>a/2||se>a/2||th>a/2)
        {
            for(int i = 1;i<=a;i++)
            {
                ans+=b[i][3].x;
            }
            if(fi>a/2)
            {
                for(int i = 1;i<=a;i++)
                {
                    if(fun[i].y==1&&fi>a/2)
                    {
                        ans=ans-fun[i].x;
                        fi--;
                    }
                }
            }
            else if(se>a/2)
            {
                for(int i = 1;i<=a;i++)
                {
                    if(fun[i].y==2&&se>a/2)
                    {
                        ans=ans-fun[i].x;
                        se--;
                    }
                }
            }
            else
            {
                for(int i = 1;i<=a;i++)
                {
                    if(fun[i].y==3&&th>a/2)
                    {
                        ans=ans-fun[i].x;
                        th--;
                    }
                }
            }
        }
        else
        {
            for(int i = 1;i<=a;i++)
            {
                ans+=b[i][3].x;
            }
        }
        cout <<ans<<endl;
    }
    return 0;
}
