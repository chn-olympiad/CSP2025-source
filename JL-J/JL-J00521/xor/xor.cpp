#include <iostream>
#include <ios>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n,k, sum=0;
    cin>>n>>k;
    int* a=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int m=1;m<=n;m++)
    {
        for(int i=0;i<n-m+1;i++)
        {
            int rs=a[i];
            for(int j=i+1;j<i+m;j++)
                rs^=a[j];
            if(rs==k)
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
