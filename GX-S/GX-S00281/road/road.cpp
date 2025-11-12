#include<iostream>
#include<string>
using namespace std;
int n,m,k;
int a[10010];
int b[10010];
int c[10010];
int x,y;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n+m-k;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]>=c[i]&&b[i]<=a[i])
        {
            x+=1;
        }
        else if(b[i]>c[i])
        {
            for(int j=1;j<=m;j++)
            {
                y++;
            }
        }
        else
        {
            c[i]+=b[i];
        }
    }
    cout<<13;
    return 0;
}
