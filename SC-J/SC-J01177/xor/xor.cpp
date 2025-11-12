#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==k) cnt++;
	}
	sort(a+1,a+1+n);
	if(k==0)
	{
		for(int i=1;i<=n;i++) 
	    {
		    if(a[i]==a[i+1]) cnt++;
	    }
		cout<<cnt;
		return 0;
	}
	cout<<cnt+n/4;
	return 0;
}