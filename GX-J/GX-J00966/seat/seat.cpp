#include<iostream>
#include<algorithm>

using namespace std;
int a[107];
int n,m;
int b[17][17];
int k;

bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)    cin>>a[i];
    k=a[1];
    sort(a+1,a+1+n*m,cmp);
    int pos=1;
    int i=1;
    while (true)
    {
        if (i%2==1)
        {
            for (int j=1;j<=n;j++)
            {
                if (a[pos]==k)
                {
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                b[i][j]=a[pos++];
            }
        }
        else
        {
            for (int j=n;j>=1;j--)
            {
                if (a[pos]==k)
                {
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                b[i][j]=a[pos++];
            }
        }
        i++;
    }
    return 0;
}
