#include <bits/stdc++.h>
using namespace std;
int n,k,m=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0) m++;
    }
    if(m==n&&k==0) cout<<n;
	return 0;
}
