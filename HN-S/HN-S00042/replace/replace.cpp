#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string a,b;
	cin>>n>>q;
	string sa[n + 2],sb[n + 2];
	for(int i = 1 ; i <= n ; i++)
		cin>>sa[i]>>sb[i];
	while(q--)
	{
		cin>>a>>b;
		int sum = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			int y = a.find(sa[i]);
			if(y == -1)continue;
			for(int j = y,op = 0 ; j <= y + sa[i].size() - 1 ; j++,op++)a[j] = sb[i][op];
			if(a == b)sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
 } 
