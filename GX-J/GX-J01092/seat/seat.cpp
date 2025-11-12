#include<bits/stdc++.h>
using namespace std;
long long a[100030]={0};
long long hl[105][105]={0};
bool kp(int a,int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i <= n*m;i++)
    {
        cin>>a[i];
    }
    int ags=n*m;
    int w=a[1];
    int js=0;
    int jh=0,jl=0;
    sort(a+1,a+1+ags,kp);
    for(int i=1;i <= n;i++)
    {
        if(i%2 != 0)
        {
            for(int j=1;j <= m;j++)
            {
                js++;
                hl[i][j]=a[js];
                if(hl[i][j] == w)
                {
                    jh=i;
                    jl=j;
                }
            }
        }
        else if(i%2 == 0)
        {
            for(int j=m;j >= 1;j--)
            {
                js++;
                hl[i][j]=a[js];
                if(hl[i][j] == w)
                {
                    jh=i;
                    jl=j;
                }
            }
        }
    }
    cout<<jh<<" "<<jl;
    return 0;
}
