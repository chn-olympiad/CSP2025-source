#include <iostream>
using namespace std;
long long a[500005];
long long fw[500005];

int main()
{

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    long long n,k;int mx=0,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fw[i]=fw[i-1]^a[i];
        for(int j=mx;j<i;j++)
        {
            long long u=fw[i]^fw[j];
            if(u==k)
            {
                mx=i;
                sum++;
                break;
            }
        }
    }
    cout<<sum;

    return 0;

}
