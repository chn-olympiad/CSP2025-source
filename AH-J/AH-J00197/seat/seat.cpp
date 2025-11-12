#include<iostream>
#include<algorithm>
using namespace std;
int a[105],cnt=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main(void)
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,maxt=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t)
        {
            maxt=i;
            break;
        }
    }
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
        {
            for(int i=1;i<=n;i++)
            {
                cnt++;
                if(cnt==maxt)
                {
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
        }
        else
        {
            for(int i=n;i>=1;i--)
            {
                cnt++;
                if(cnt==maxt)
                {
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
