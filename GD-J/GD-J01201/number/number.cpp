#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+5;
string s;
long long a[N],pot=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[pot++]=s[i]-'0';
	}
	sort(a,a+pot);
	for(int i=pot-1;i>=0;i--)cout<<a[i];
	return 0;
}
