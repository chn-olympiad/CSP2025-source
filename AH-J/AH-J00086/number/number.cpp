#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],flag[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int cnt=0;
	for (int i=0;i<n;i++)
	{
		if (s[i]>='0'&&s[i]<='9') {a[cnt]=s[i]-'0';cnt++;}
	}
	//huai le kuai pai wang le zhi neng yong tong pai le
	for (int i=0;i<cnt;i++)
		flag[a[i]]++;
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=flag[i];j++)
			cout<<i;
	}
	return 0;
}
