#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000002];
int main()
{
	freopen("number.in","w",stdin);
	freopen("number.out","s",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)if(a[i]>='0'&&a[i]<='9')b[a[i]-'0']++;
	for(int i=9;i>=0;i--)
	{
		while(b[i])
		{
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}

