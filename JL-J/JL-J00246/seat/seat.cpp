#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
struct node
{
    int cnt,id;
};
node f[105];

bool cmp(node x,node y)
{
    if(x.cnt==y.cnt)
    {
        return x.id<y.id;
    }
    else{
        return x.cnt>y.cnt;
    }

}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int num=2;
    for(int i=1;i<=n*m;i++)
    {
        cin>>f[i].cnt;
        f[i].id=i;
    }
    sort(f+1,f+n*m+1,cmp);
    int x=1,y=1;
    a[x][y]=1;
    //x++;
    while(num<=n*m)
    {
        //a[x][y]=num;
        if(x>n)
        {
            x--;
            y+=1;
            //cout<<x<<y<<endl;
            a[x][y]=num-1;
            num--;
        }
        else if(x<1)
        {
            x++;
            y+=1;
            a[x][y]=num-1;
            num--;
        }
        else
        {
            if(y%2==0)
            {
                x--;
               a[x][y]=num;
            }
            else
            {
                x++;
                a[x][y]=num;
            }
        }
        num++;
    }

    int z=0;
    for(int i=1;i<=n*m;i++)
    {
        if(f[i].id==1)
        {
            z=i;
            break;
        }
    }
    //cout<<z<<endl;;
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=m;y++)
        {
            if(a[x][y]==z)
            {
                cout<<y<<" "<<x;
                return 0;
            }
        }
    }

}
