#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> a(10);
	string s;
	cin>>s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i = 9;i >=0;i--)
	{
		while(a[i]--)
		{
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
