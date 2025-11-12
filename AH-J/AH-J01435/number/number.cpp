#include<bits/stdc++.h>
using namespace std;
long long a[1000005],i2;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
		{	i2++;
			a[i2]=s[i]-'0';
		}
	sort(a+1,a+1+i2);
	for(int i=i2;i>0;i--)	cout<<a[i];
	return 0;
}
