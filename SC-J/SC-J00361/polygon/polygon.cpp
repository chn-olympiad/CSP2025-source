#include <bits/stdc++.h>
using namespace std;
int n,ans,a[5005],mx,s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		mx=max(a[i],mx);
		s+=a[i];
	}
	mx*=2;
	if (s>mx)
	{
		ans=1;
	}
	cout << ans;
	fclose(stdin);
    fclose(stdout); 
	return 0;
}