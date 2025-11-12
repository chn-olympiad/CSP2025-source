#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000010],n=1;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
		{
			
			a[n]=s[i]-'0';
			n++;
		}
	n--;
	sort(a+1,a+n+1);
	if(a[n]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=n;i>=1;i--)
		std::cout<<a[i];
	return 0;
}
