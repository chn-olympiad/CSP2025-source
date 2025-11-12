#include<bits/stdc++.h>
#define endl '\n'
#define LX long long
using namespace std;
set<int, greater<int>> a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int r = 0;
	for(int i=1;i<=n*m;i++)
	{
		int j;
		cin >> j;
		if(i == 1)r = j;
		a.insert(j);
	}
	int place = 1;
	for(auto lx : a)
	{
		if(lx == r) break;
		else		place++;
	}
	int pm = place / m;
	int lie = (place%m==0) ? pm : pm + 1;
	int pp = place - 2 * ((lie+1)/2 - 1) * m;
	int hang = (lie%2) ? pp : 2 * m - pp +1;
	cout<<lie<<" "<<hang<<endl;
	return 0;
}
