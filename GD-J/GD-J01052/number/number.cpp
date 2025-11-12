#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	vector<int> b;
	cin>>a;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b.push_back(a[i]-'0');
		}
	}
	sort(b.begin(),b.end(),cmp);
	for(int i:b) cout<<i;
	return 0;
}
