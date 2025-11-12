#include <bits/stdc++.h>
using namespace std;
int n,k,a = 0,b = 0;
int main()
{
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int ans,c[500005];
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		while(a > c[i])
		{
			a++;
			b--;
			ans = n%(a + b);
			
		}
		
	}
	cout << ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
