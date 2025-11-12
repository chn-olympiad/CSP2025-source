#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,c=0;
    cin>>n;
    long long a[n];
    for(long long i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(long long i=3;i<n;i++)
        for(long long j=0;j+i<n;j++)
        {
            long long h=0,m=-1;
            for(long long k=j;k<i;k++){h+=a[k];m=max(a[k],m);}
            if(h>m*2)c++;
            //cout<<c<<endl;
        }
    cout<<c;
    return 0;
}
