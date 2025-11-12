#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
int N=1e6+5;
bool cmp(int a,int b)
{return a>b;}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int k=0,z=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k++;
		}
	}
	vector<int>a(k);
	int x=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[x]=s[i]-48;
			x++;
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<=k-1;i++)
		cout<<a[i];
	cout<<endl;
	return 0;
}
