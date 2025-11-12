#include <bits/stdc++.h>

using namespace std;
const int MAX=1e5+5;
int a[MAX][4],n,d[4];
struct point{
    int num,s,cla;
}poi[MAX];
bool com(point a,point b)
{
    return a.s<b.s;
}
void change(int x,int more)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(j!=x&&poi[i].cla==x)
            {
                poi[i].s=min(poi[i].s,a[poi[i].num][x]-a[poi[i].num][j]);
            }
        }
    }
    sort(poi+1,poi+n+1,com);
    for(int i=1;i<=more;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(j!=x&&a[poi[i].num][x]-a[poi[i].num][j]==poi[i].s)
            {
                poi[i].cla=j;
            }
        }

    }

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        d[1]=0;
        d[2]=0;
        d[3]=0;
        for(int i=1;i<=n;i++) poi[i].s=1e5;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            poi[i].num=i;
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
            {
                d[1]++;
                poi[i].cla=1;
            }
            else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
            {
                d[2]++;
                poi[i].cla=2;
            }
            else
            {
                d[3]++;
                poi[i].cla=3;
            }
        }
        for(int i=1;i<=3;i++)
        if(d[i]>n/2) change(i,d[i]-n/2);
        int sum=0;
        for(int i=1;i<=n;i++) sum+=a[poi[i].num][poi[i].cla];
        cout<<sum<<endl;
    }

    return 0;
}
