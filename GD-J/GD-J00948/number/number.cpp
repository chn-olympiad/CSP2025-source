#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
int a[1000010],k; 
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[++k]=s[i]-'0';
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;--i)
		cout<<a[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
