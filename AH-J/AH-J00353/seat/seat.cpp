#include<bits/stdc++.h>
using namespace std;

int n,m;
int num;
int a[105];
int table[15][15];

bool cmp(int x,int y)
{
    return x>y;
}

void out(int x,int y)
{
    cout<<x<<" "<<y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    num=n*m;
    for(int i=1;i<=num;i++)
        cin>>a[i];
    int p=a[1];
    sort(a+1,a+num+1,cmp);
    int now=0;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
            for(int j=1;j<=n;j++)
                table[j][i]=a[++now];
        else
            for(int j=n;j>=1;j--)
                table[j][i]=a[++now];
    }
    bool ok=1;
    for(int i=1;i<=n&&ok;i++)
        for(int j=1;j<=m&&ok;j++)
            if(table[i][j]==p)
                out(j,i),ok=0;
    return 0;
}
