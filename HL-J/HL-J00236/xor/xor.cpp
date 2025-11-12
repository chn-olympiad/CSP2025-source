#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n = 0,k = 0;
	cin>>n>>k;
	int _and = 0;
	int cnt = 0;
	for(int i = 0 ;i < n;i++)
	{
		int a = 0;
		cin>>a;
		_and = _and^a;
		if(a == k)
		{
			cnt++;
			_and = 0;
		}
		if(_and==k)
		{
			cnt++;
			_and = 0;
		}
	}
	cout<<cnt;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
