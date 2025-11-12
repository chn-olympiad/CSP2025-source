#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],Rcj,k,qwerty[15][15];
bool cmp(int x,int y){
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<= n*m;i++){
		cin >> a[i];
	}
	Rcj = a[1];
	sort(a+1,a + n*m + 1,cmp);
	
	int ans = 1;
	for (int i = 1;i<=m;i++)
	{
		if(i%2 == 1){
			for(int j = 1;j<=n;j++){
				if (a[ans] == Rcj){
					cout << i << ' ' << j << endl;
					return 0;
				}
				qwerty[i][j] = a[ans];
				ans++;
				
			}
		}
		else{
			for(int j = n;j>=1;j--){
				if (a[ans] == Rcj){
					cout << i << ' ' << j << endl;
					return 0;
				}
				qwerty[i][j] = a[ans];
				ans++;
			}
		}
	}
	return 0;
}
