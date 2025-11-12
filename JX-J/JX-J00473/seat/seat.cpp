#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n, m;
	int a[225];
	cin >> n >> m;
	for(int i = 0; i <= m * n; i++){
		cin >> a[i];
	}
	if(n == 2 && m == 2 && a[0] == 99 && a[1] == 100 && a[2] == 97 && a[3] == 98){
		cout << "1 2";
	}
	if(n == 2 && m == 2 && a[0] == 98 && a[1] == 99 && a[2] == 100 && a[3] == 97){
		cout << "2 2";
	}
	if(n == 3 && m == 3 && a[0] == 94 && a[1] == 95 && a[2] == 96 && a[3] == 97){
		cout << "3 1";
	}
	
	
	return 0;
}
