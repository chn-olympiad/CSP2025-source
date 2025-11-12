#include<bits/stdc++.h>
#define int long long
using namespace std;
unsigned long long rp=-1;
int n,m,a[105],r;
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i*m-m+j]==r)
            {
                if(i%2)cout<<i<<' '<<j;
                else cout<<i<<' '<<m+1-j;
                return 0;
            }
        }
    }
    return 0;
}

//mo bai xst dalao!
//mo bai wyx dalao!
//mo bai cyh dalao!
//#Shang4Shan3Ruo6Shui4
