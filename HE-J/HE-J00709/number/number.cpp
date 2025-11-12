#include <bits/stdc++.h>
using namespace std;
string s;
long long sum = 0,ans = 0,len1,a[100010]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len1 = s.size();
	if (len1 == 1)
	{
		cout << s;
		return 0;
	}
	for (int i = 0; i < len1; i ++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			sum ++;
		}
		else 
		{
			return 0;
		}
		for(int j=0;j<sum;j++)
		{
			a[j]=s[i];
			sort(a+1,a+sum+1);
			ans+=a[j];
		}
	}
	cout<<ans;
	return 0;
}
