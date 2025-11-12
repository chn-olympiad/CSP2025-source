# include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
struct node
{
    int num,flag;
}a[N];
int n,m,sx,sy;

bool cmp(node a,node b)
{
    return a.num>b.num;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i].num;
        a[i].flag=0;
        if(i==1)
            a[i].flag=1;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].flag==1)
        {
            sy=i/n+1;
            if(i%n==0)
                sy-=1;
            if(sy%2==0)
                sx=i%n+1;
            else
                sx=i%n;
            if(i/n%2==1)
                sx=n;
        }
    }
    cout << sy << " " << sx;
    return 0;
}
