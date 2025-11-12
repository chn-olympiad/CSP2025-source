#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000005],cnt;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int o=s.length();
	for(int i=0;i<o;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[i]=s[i]-48;
			cnt++;
		}
	 } 
	sort(a,a+o,greater<int>());
	for(int i=0;i<cnt;i++)
	{
		cout<<a[i];	 
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
 } 
