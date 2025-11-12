#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int score[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r_s;
    cin >> n >> m;
    for(int i=1;i<=m*n;i++)
        scanf("%d",&score[i]);
    r_s=score[1];
    sort(score+1,score+n*m+1,cmp);
    int x=1,y=1,ds=1;
    if(r_s==score[1])
    {
        cout<<"1 1";
        return 0;
    }
    for(int i=2;i<=n*m;i++)
    {
        if(ds==1)
        {
            if(x+1<=n)x++;
            else if(y+1<=m)y++,ds=2;
        }
        else if(ds==2)
        {
            if(x-1>=1)x--;
            else if(y+1<=m)y++,ds=1;
        }

        if(score[i]==r_s)
        {
            cout<<y<<" "<<x;
            return 0;
        }
    }
    return 0;
}
