#include <bits/stdc++.h>
using namespace std;
long long A=0;
long long KQ(long long a,vector<long long> data())
{

}
int main()
{
    freopen("polygon.in","r",stdin);
    long long n,sum=0;
    cin>>n;
    vector<long long> data(n);
    for(long long i=0;i<n;i++)
    {
        cin>>data[i];
    }
    for(long long i=3;i<=n;i++)
    {
        sum+=KQ(i,data);
    }
    return 0;
}
