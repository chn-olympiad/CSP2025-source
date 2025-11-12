#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000006];
int num=0;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<64)
		{
			a[num]=s[i]-48;
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--)
	{
		cout<<a[i];
	}

	return 0;
	fclose(stdin);
	fclose(stdout);
}
