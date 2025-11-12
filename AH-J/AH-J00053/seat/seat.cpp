#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int b[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int ans = a[1];
	int nm = n * m;
	sort(a + 1, a + 1 + nm);
	int k = nm;
	for(int i = 1; i <= m; i++) 
	{
		if(i % 2 == 1) 
		{
			for(int j = 1; j <= n; j++) 
				b[i][j] = a[k--];
		}
		else 
		{
			for(int j = n; j >= 1; j--) 
				b[i][j] = a[k--];
		}
	}
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
		{
			if(b[i][j] == ans)
			{
				cout << i << " " << j;
				return 0;
			}
		}
	return 0;
}
