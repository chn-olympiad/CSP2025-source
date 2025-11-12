#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    int xh;
}s[105];
int seat[15][15];
bool cmp(node x,node y)
{
    return x.a>y.a;
}
int main()
{
    int n,m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>s[i].a;
        s[i].xh=i;
    }
    sort(s+1,s+1+n*m,cmp);
    int h=1;//di h gexuesheng
    bool direction=0;//xia0 shang1
    int i=1,j=1;
    while(1)
    {
        seat[i][j]=s[h].xh;
        h++;
        if(h>n*m)break;

        if(direction==0)
        {
            if(i+1<=n)
            {
                i++;
            }
            else
            {
                if(j+1<=m)j++;
                direction=1;
            }
        }
        else if(direction==1)
        {
            if(i-1>=1)
            {
                i--;
            }
            else
            {
                if(j+1<=m)j++;
                else break;
                direction=0;
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int kk=1;kk<=m;kk++)
        {
            if(seat[k][kk]==1)
            {
                cout<<kk<<" "<<k;
                return 0;
            }
        }
    }
    return 0;
}
