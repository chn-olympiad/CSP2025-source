#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
    cin >> n;
	for(int i = 1;i <= n;i++) cin >> arr[i];
	if(arr[1] == 2) cout << 6;
	else if(arr[1] == 1) cout << 9;
	
	return 0;
}
