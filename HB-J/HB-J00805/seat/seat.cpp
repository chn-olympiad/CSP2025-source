#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int cnt;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int sum=0;
    cnt=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    int x=1;
    int hang=1,lie=1;
    while(5)
    {
        if(a[x]==cnt)
            break;
        if(lie%2==1)
        {
            if(hang==n)
            {
                hang=n;
                lie++;
            }
            else
                hang++;
        }
        else
        {
            if(hang==1)
            {
                lie++;
                hang=1;
            }
            else
                hang--;
        }
        x++;
    }
    cout<<lie<<" "<<hang;
    return 0;
}
