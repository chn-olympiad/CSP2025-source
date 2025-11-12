#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int s,a[10005],ans=0;
	cin>>s;
	for(int i=1;i<=s;i++)
	{
		if(s[i]>ans)
		{
			ans+=s;
		}
	}
	cout<<ans;
	return 0;
}
