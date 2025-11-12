#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	string s;
	int w=0;
	cin >>s;
int c=s.size()+1;
int g[c];
	for(int i=0;i<=s.size()+1;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
		   g[++w]=int(s[i]);
		}
	}
	cout << endl;
	sort(g+1,g+w+1);
	for(int i=w;i>=1;i--)
	cout<< char(g[i]);
	return 0;//我不甘心，明明样例都能过，可偏偏可时间复杂度在 1.70左右，限制1.00 。。明年见 
 }
 /*#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	int b;
		
	cin >>s;
	vector <int> a;
	for(int i=0;i<=s.size()+1;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			 b=s[i]-'0';
			a.push_back(b);
		
		}
	}
	b=a.size();
	int g[b+1];
	for(int i=0;i<=b-1;i++)
	{
		g[i]=a[i];
	}
	sort(g,g+b+1);
	for(int i=b;i>=1;i--)
	cout << g[i];
	return 0;
 } */ 
