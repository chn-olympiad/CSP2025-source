#include<bits/stdc++.h>
using namespace std;
string n;
long long a[1000010],num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n.size();i++)
		if(n[i]>='0'&&n[i]<='9')
		{
			num++;
			a[num]=n[i]-'0';
		}
	sort(a+1,a+num+1);
	for(long long i=num;i>=1;i--)
		cout<<a[i];
	return 0;
}