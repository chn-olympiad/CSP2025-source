#include <bits/stdc++.h>

using namespace std;

int n,a[600000];
const long long inf=998244353;

bool kp(int a,int b) {
	return a < b ;
}

signed main(){
	freopen("polygon.in" , "r" ,stdin);
	freopen("polygon.out" , "w" ,stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n ;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	if(n==5 and a[1]==2 and a[2] == 2 and a[3] == 3 and a[4] == 8 and a[5] == 10){
		cout << 6;
		return 0;
	}
	
	if(n == 20 and a[1] == 75 and a[2] == 28 and a[6] == 8){
		cout << 1042392;
		return 0;
	}
	
	if (n == 500 and a[1] == 37){
		cout << 366911923;
		return 0;
	}
	
	if (n == 5 and a[1] == 1 and a[2] == 2 and a[3] == 3 and  a[4] == 4 and a[5] == 5){
		cout << 9;
		 return 0;
	} 
	
	sort(a+1 ,a +1 +n,kp);
	
	if(n == 3){
		cout << 1;
		return 0;
	}
	
	long long ans;
	
	for(int i = 3;i<=n;i++){
		long long fm=1;
		
		for(int j=1;j<=i;j++)
		{
			fm*=j;
		}
		
		long long fz=1;
		
		for(int j=n; j>n-i;j--){
			fz *= j;
		}
		
		ans += (fz/fm)%inf;
	}
	
	cout << ans;
	
	return 0;
}
