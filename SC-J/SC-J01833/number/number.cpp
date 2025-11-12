#include<bits/stdc++.h>
using namespace std;
long long a[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.length();i++)
	{
	if(s[i]>='0'&&s[i]<='9')
	{
		a[s[i]-'0']++;
	}
	
	}
	for(long long i=9;i>=0;)
	{
	if(a[i]>0)
	{
		a[i]--;
		cout<<i;
		}
		else{
			i--;
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 