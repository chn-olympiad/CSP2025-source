#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=0;
	char a[1000001];
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[t]=s[i];
			t++;
		}
	}
	sort(a,a+t);
	for( int i=t;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
