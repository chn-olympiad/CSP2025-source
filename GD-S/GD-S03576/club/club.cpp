#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n, t, maxx = - 1, sum = 0;
	int a[100005], b[100005], c[100005], a1, b1, c1;
	cin >> t;
	for(int i = 1;i<=t;i++)
	{
		cin >> n;
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			sum = 0;
			a1 = 0, b1 = 0, c1 = 0;
			if(a[i]>=b[i]&&a[i]>=c[i]&&a1<=n/2)
			{
				a1++;
				sum += a[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]&&b1<=n/2)
			{
				b1++;
				sum += b[i];
			}
			else if(c[i]>=a[i]&&c[i]>=b[i]&&c1<=n/2)
			{
				c1++;
				sum += c[i];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
