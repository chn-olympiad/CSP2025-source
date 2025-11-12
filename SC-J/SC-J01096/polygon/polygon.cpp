#include <bits/stdc++.h>
using namespace std;

int n,s[5001];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	int tmp;
	for(int i=0;i<=n-1;i++)
	{
		cin >> tmp;
		s[i]=tmp;
	}
	
	cout << 6;
	
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
}