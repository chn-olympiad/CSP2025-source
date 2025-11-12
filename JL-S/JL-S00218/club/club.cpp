#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,maxx,maxxx,maxxxx;
int a[100000][5],mid,tot1,tot2,tot3;
int lim;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(int c=1;c<=n;c++)
    {
        cin>>m;
        mid=m/2;
        for(int y=1;y<=m;y++)
        {
            for(int w=1;w<=3;w++)
            {
                cin>>a[y][w];
            }
            if(a[y][1]>=a[y][2]&&a[y][1]>=a[y][3]&&a[y][2]>=a[y][3])
                maxx=a[y][1],maxxx=a[y][2],maxxxx=a[y][3],tot1++;
            if(a[y][1]>=a[y][2]&&a[y][1]>=a[y][3]&&a[y][3]>=a[y][2])
                maxx=a[y][1],maxxx=a[y][3],maxxxx=a[y][2],tot1++;
            if(a[y][2]>=a[y][1]&&a[y][2]>=a[y][3]&&a[y][1]>=a[y][3])
                maxx=a[y][2],maxxx=a[y][1],maxxxx=a[y][3],tot2++;
            if(a[y][2]>=a[y][1]&&a[y][2]>=a[y][3]&&a[y][3]>=a[y][1])
                maxx=a[y][2],maxxx=a[y][3],maxxxx=a[y][1],tot2++;
            if(a[y][3]>=a[y][2]&&a[y][3]>=a[y][1]&&a[y][1]>=a[y][2])
                maxx=a[y][3],maxxx=a[y][1],maxxxx=a[y][2],tot3++;
            if(a[y][3]>=a[y][2]&&a[y][3]>=a[y][1]&&a[y][2]>=a[y][1])
                maxx=a[y][3],maxxx=a[y][2],maxxxx=a[y][1],tot3++;
            cnt=cnt+maxx;
            maxx=0;
        }
        //if(tot1<=mid&&tot2<=mid&&tot3<=mid)
        cout<<cnt<<"\n";
        cnt=0;
        //tot1=0,tot2=0,tot3=0;
        }
    return 0;

}
