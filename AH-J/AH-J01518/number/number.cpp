#include<bits/stdc++.h>
using namespace std;
long long a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long i,j;
	string w;
	cin>>w;
	for(i=0;i<w.size();i++)
	{
		if(w[i]>='0'&&w[i]<='9')
		{
			a[w[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--)
	{
		for(j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
