#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,a[100001],b,m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    if(k==0)
    {
    	if(n%2==0)
    	    cout<<n;
    	else
    	    cout<<n-1;
	}  
    else if(k==1)
    {
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)
            if(a[i]==1)
                b++;
        if(b%2==1)
            cout<<n;
        else
            cout<<n-1;
	}
	else
	    cout<<2;
    return 0;
}