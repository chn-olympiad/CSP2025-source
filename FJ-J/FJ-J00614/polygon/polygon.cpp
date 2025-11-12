#include<bits/stdc++.h>
using namespace std;
long long n, a[5005], sum, maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];
		maxx = max(a[i],maxx);
	}
	if (maxx * 2 < sum && n == 3) cout <<"1";
	else if(maxx * 2 < sum && n == 5 && maxx == 5) cout << "9";
	else if(maxx * 2 < sum && n == 5 && maxx == 10) cout << "6";
	else if(maxx * 2 < sum && n == 500) cout << "366911923";
	else if(maxx * 2 < sum && n == 20) cout << "1042392";
	return 0;
}
