#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,q;
string a[N],b[N],s1[N],s2[N];


int main()
{
	freopen("replace.out","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin >> a[i] >> b[i];
	}
	
	for(int i=1;i<=q;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i].size()<s1[j].size())	
				cnt++;
		}
		cout << cnt << endl;
	}
	

	return 0;
}
