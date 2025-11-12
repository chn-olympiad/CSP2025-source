#include <bits/stdc++.h>
using namespace std;
int sc[100005];
int zw[105][5],xb=0;
int zz[105][5],xb2=0;
int h,l;
bool cmp(int x,int y)
{
    return x>y;
}
bool check(int x,int y)
{
    if(x<1 || x>l)
        return 0;
    if(y<1 || y>h)
        return 0;
    return 1;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> h >> l;
    for(int i=1;i<=h*l;i++)
    {
        cin >> sc[i];
    }
    int score=sc[1];
    sort(sc+1,sc+h*l+1,cmp);
    int x=1,y=1;
    bool m=0;
    if(l%2==0)
    {
        do
        {
            zw[++xb][1]=x;
            zw[xb][2]=y;
            if(m==0)
            {
                if(y==h)
                {
                    x++;
                    m=1;
                }
                y++;
            }
            if(m==1)
            {
                if(y==1)
                {
                    x++;
                    m=0;
                }
                y--;
            }
        }while(x!=l || y!=1);
        zw[++xb][1]=l;
        zw[xb][2]=1;
    }
    if(l%2==1)
    {
        do
        {
            zw[++xb][1]=x;
            zw[xb][2]=y;
            if(m==0)
            {
                if(y==h)
                {
                    x++;
                    m=1;
                }
                y++;
            }
            if(m==1)
            {
                if(y==1)
                {
                    x++;
                    m=0;
                }
                y--;
            }
        }while(x!=l || y!=h);
        zw[++xb][1]=l;
        zw[xb][2]=h;
    }
    for(int i=1;i<=xb;i++)
    {
        int x=zw[i][1],y=zw[i][2];
        if(check(x,y))
        {
            zz[++xb2][1]=x;
            zz[xb2][2]=y;
        }
    }
    int xx;
    for(int i=1;i<=h*l;i++)
    {
        if(score==sc[i])
        {
            xx=i;
            break;
        }
    }
    cout << zz[xx][1] << " " << zz[xx][2] << endl;
    return 0;
}
