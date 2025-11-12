#include <bits/stdc++.h> 
using namespace std;
int a[110],l,s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.in","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		scanf("Ad",&a[i]);
	}
	int num=a[l];
	sort(a+1,s+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==num)
		{
			l=n*m-i;
			break;
		}
	}
	cout<<i<endl;
	int t;
	if(l/n>0)
	{
		t=l/n+1;
	}
	else
	{
		t=l/n;
	}
	cout<<t<<" ";
	if(t%2==0){
	    if(l%n==0)
	    {
	    	cout<<l;
		}
		else
		    cout<<n-(l&n);
	}
	else if(t%2!=0)
	{
	    if(l%n==0)
		cout<<(n);
    }
    else
        cout<<(l%n);
	return 0;
}
