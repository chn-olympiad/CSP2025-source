#include<bits/stdc++.h>
using namespace std;
int s[500005]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0||k==1)
	{
		int a=0,b=0;
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
			if(s[i]==1)a++;
			else b++;
			if(s[i]==1&&s[i-1]==1)
			{
				b++;
				s[i]=0;
			} 
		}
		if(k==1)cout<<a;
		else
		{	
			cout<<b;
		}
	}
	else
	{	
	    int tmp,ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			if(tmp==k)ans++;
		}
		cout<<ans;
	}
	return 0;
 } 
