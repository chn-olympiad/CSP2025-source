#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int score,num;
}a[107],ans[17][17];
bool cmp(node x,node y)
{
    return x.score>y.score;
}
int n,m,t=0,x=1,y=1,dir=1/*1 down -1 up*/;
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[++t].score;
            a[t].num=t;
        }
    }
    sort(a+1,a+1+t,cmp);
    ans[1][1]=a[1];
    for(int i=2;i<=t;i++)
    {
        if(x==n&&dir==1)
        {
            y++;
            dir=-1;
        }
        else if(x==1&&dir==-1)
        {
            y++;
            dir=1;
        }
        else
        {
            x+=dir;
        }
        ans[x][y]=a[i];
        if(a[i].num==1)
        {
            cout<<y<<' '<<x<<endl;
            break;
        }
    }
    return 0;
}
//SAYONALA TOBETE EVANGELION
