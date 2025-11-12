#include<bits/stdc++.h>
using namespace std;
long long a[1000009];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt=0,sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	if(cnt==1)
		cout << a[0];
	sort(a,a+s.size());
	for(int i=s.size()-1;i>0;i--)
	{
		sum++;
		cout << a[i];
		if(sum==cnt)
			return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
