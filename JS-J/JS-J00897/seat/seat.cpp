#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[110];
int mp[15][15];
int R;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                cnt++;
                mp[j][i]=a[cnt];
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                cnt++;
                mp[j][i]=a[cnt];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==R)
            {
                cout<<j<<" "<<i;
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
