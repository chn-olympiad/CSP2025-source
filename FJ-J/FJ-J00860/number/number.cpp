#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n=1;
	cin >>s;
	for(int i=0;i < s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
		{
			
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i >= 2;i--)
	{
		cout<<a[i];
	}
	return 0;
}
