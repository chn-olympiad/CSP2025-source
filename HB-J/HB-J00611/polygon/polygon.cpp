#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,a[5000],he=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
         cin>>a[i];
         he+=a[i];
    }
    sort(a,a+n);
    if(n==3)
    {
        if(he>(2*a[n-1]))
        {
         cout<<1;
        }
        else
        {
        cout<<0;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
