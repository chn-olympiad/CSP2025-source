#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[1000000],sum1=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(k=0)
    {
        if(n=1)
        {
            sum1=0;
        }
        else
        {
            sum1=(n-(n%2))/2;
        }
    }
    cout << sum1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
