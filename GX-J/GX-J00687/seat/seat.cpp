#include<bits/stdc++.h>
using namespace std;
long long s[100004][100005];
long long a[100004];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,r=1,c=1,sum;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    sum=n*m;
    c=a[1]%sum;
    c++;
    while(c>m)
    {
        if(c>m)
        {
            c--;
            r++;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
