#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long sum = 0,Min = 1e18;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		sum += z;
	}
	for(int i = 1;i <= k;i++){
		long long id;
		int Max = 0;
		cin >> id;
		for(int j = 1;j <= n;j++){
			int x;
			cin >> x;
			Max = x;
		}
		sum -= Max;
		Min = min(Min,id);
	}
	cout << sum - Min;
	
	return 0;
}
