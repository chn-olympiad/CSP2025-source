#include <bits/stdc++.h>
using namespace std;
int ans[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int n=a.size();
	int t=0;
	for (int i=0;i<n;i++)
	{
		if (a[i]>='0' && a[i]<='9')
		{
			ans[t]=a[i]-'0';
			t++;
		}
	}
	sort(ans,ans+t);
	for (int i=t-1;i>=0;i--)
	{
		cout << ans[i];
	}
	return 0;
}
