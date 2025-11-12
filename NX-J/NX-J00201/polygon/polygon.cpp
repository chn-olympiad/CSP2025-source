#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[100000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int maxn=a[n];
    int sb=n-2;
    int sum=0;
    int cnt=0;
    for(int i=1;i<=n-1;i++)
    {
        for(int p=i;p<=n-sb-1;p++)
        {
            sum+=a[p];
            if(sum<a[n])
            {
                sb-=1;
            }
            if(sum>maxn)
            {
                cnt+=n-p;
                break;
            }
        }
        sum=0;
        cout<<endl;
    }
    cout<<cnt;

}
