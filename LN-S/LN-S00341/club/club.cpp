#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int arr[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n == 2)
		{
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			int m1 = max(a + e,a + f);
			int m2 = max(b + d,b + f);
			int m3 = max(c + d,c + e);
			cout<<max(max(m1,m2),m3)<<endl;
			continue;
		}
		int a = 0,b = 0,c = 0;
		int sum = 0;
		for(int i = 1;i <= n;i++)
		{
			cin>>a>>b>>c;
			arr[i] = b;
		}
		sort(arr + 1,arr + n + 1);
		for(int i = n / 2 + 1;i <= n;i++)
		{
			sum += arr[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
