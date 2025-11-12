#include <bits/stdc++.h>
using namespace std;
int cj[105];
bool cmp(int &a,int &b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n,m,r,jl = 1;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
		cin >> cj[i];
	r = cj[1];
	sort(cj+1,cj+n*m+1,cmp);
//	for (int i = 1;i <= n*m;i++)
//		cout << cj[i] << ' ';
	for (int i = 1;i <= n*m;i++)
	{
		if (cj[i] == r)
		{
			jl = i;
			break;
		}
	}
	int ann,anm;
//	cout << jl <<'\n';
	ann = int(ceil(1.0 * jl / n));
	if (!(ann % 2))
	{
		if (!(jl%n))
			anm = 1;
		else
			anm = n - jl % n + 1;
	}
	else
	{
		if (!(jl % n))
			anm = n;
		else
			anm = jl % n;
	}
		
	cout << ann << ' '<< anm;
	return 0;
} 
