#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,seat=0;
    cin >> m >> n;
    int a[n+5][m+5];
    int s=n*m;
    int b[s+5];
    for(int i=1;i<=s;i++)
    {
        cin >> b[i];
    }
    int r=b[1];
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(b[j+1]<=b[j])
            {
                swap(b[j+1],b[j]);
            }
        }
        if(r==b[i])
        {
            seat=s-i+1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(seat<=n)
            {
                if(seat==j)
                {
                    if(i%2==1&&i==1)
                    {
                        cout << i << " " << j;
                        return 0;
                    }
                    if(i%2==1&&i>1)
                    {
                        cout << i << " " << n-j+1;
                        return 0;
                    }
                    else if(i%2==0)
                    {
                        cout << i << " " << j;
                    }
                }
            }
            else if(seat>=n)
            {
                seat-=n;
                break;
            }
        }
    }



}
