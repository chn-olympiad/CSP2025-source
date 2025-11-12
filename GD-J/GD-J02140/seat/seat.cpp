#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m;
	cin >> n >> m;
	long long ans[n*m];
	for(long long i = 0;i < n*m;i ++){
		cin >> ans[i];
	}
	int num = ans[0];
	sort(ans,ans+n*m,cmp);
	for(int i =0;i < n*m;i ++){
	}
	int l = 0,r = n*m-1;
	int mid = (l+r)/2;
	while(ans[mid] != num){
		mid = (l+r)/2;
		if(ans[mid] > num){
			l = mid;
		}else{
			r = mid;
		}
	}
	mid += 1;
	if((mid / m+1) % 2 == 0){
		cout << mid / n+1 << ' ' << abs(m - mid / m+1) << endl;
	}else{
		cout << mid / n+1 << ' ' << mid % m << endl;
	}
	return 0;
}
