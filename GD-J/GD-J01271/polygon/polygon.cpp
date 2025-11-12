#include<bits/stdc++.h>
using namespace std;
int a[5005];
int cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int sum=0;
	int mx=-1;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		sum+=a[i];
		mx=max(a[i],mx);
	}
	if(n>=3&&sum>2*mx) cout << 1;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
