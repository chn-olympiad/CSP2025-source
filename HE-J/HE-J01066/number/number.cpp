#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0;
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>='0'&&s[i]<='9') 
		{
			a[i]=int(s[i]-48);
			n++;
		}
	}
	sort(a,a+1+n);
	for(int i=n;i>=1;--i)
	{
		cout<<a[i];
	}
	return 0;
}
/*290es1q0*/
