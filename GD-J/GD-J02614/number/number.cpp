#include<bits/stdc++.h>
using namespace std;
int a[1000001];
string s;
int main()
{
	freopen{"number.in","r",stdin};
	freopen{"number.out","w",stdin};	
	int n,ans=0;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		if(n%10<=i)
		{
			a[i];
		}else{
			a[n]++;
		}
		for(int j=0;j<=n;j++)
		{
			if(j<=n)
			{
				ans++;
			}else{
				continue;
			}
		} 
	}
	cout<<ans;
}
