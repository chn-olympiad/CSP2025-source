#include<bits/stdc++.h>
using namespace std;
int n,m,k;

vector<int> a[1000005]; 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1,x,y,z;i <= m;i++){
		cin >> x >> y >> z;
		a[x].push_back(y);
		a[y].push_back(x); 
	}
	
	return 0;
}

