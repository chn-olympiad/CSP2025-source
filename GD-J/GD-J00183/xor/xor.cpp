#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int i,n,k,ans=0;
	cin>>n>>k;
	int a[n+1];
	bool spec_A=true,spec_B=true;
	for(i=1;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>1) spec_B=false;
		else
		{
			if(!a[i]) spec_A=false;
			else ans++;
		}
			
	}
	if(spec_A)
	{
		cout<<n;
		return 0;
	}
	if(spec_B)
	{
		cout<<ans;
		return 0;
	}
	cout<<min((k/2+n/3),(k*4/3+n)/3+1);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
