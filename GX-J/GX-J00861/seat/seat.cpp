#include<bits/stdc++.h>
using namespace std;
long long a[121];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,z;
    cin>>n>>m>>z;
    int s=n*m;
    for(int i=1;i<=s;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+s);
    a[s+1]=101;
    long long c=1,r=1;
    for(int i=s;i>=1;i--)
    {
        if(a[i]>=z&&a[i-1]<=z)
        {
            cout<<c+1<<" "<<r;
            return 0;
        }
        if(r==n&&c%2!=0||r==1&&c%2==0) c++;
        else if(c%2!=0) r++;
        else r--;
    }
    return 0;
}
