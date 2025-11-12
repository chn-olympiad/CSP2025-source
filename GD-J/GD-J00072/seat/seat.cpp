#include<bits/stdc++.h>
using namespace std;
int n, m, a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> a[i*m+j];
		}
	}
	int R_score = a[1];
	sort(a+1,a + n*m + 1, greater<int>()) ;
	for (int i = 0; i < n; ++i)
	{
		for(int j = 1; j <= m; j ++){
			if(a[i*m+j]==R_score){
				cout << i+1 << ' ' << (i%2==0)?j:m-j+1;
				return 0; 
			}
		}
	}
	return 0;
}
