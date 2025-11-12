#include<bits/stdc++.h>
using namespace std;

int const MAXN = 1e5 + 5;
int b[MAXN][3];
int a[MAXN][5];
int c[MAXN];
int cnt;
int minn = INT_MAX;
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	while(t--){
		c[1]=0,c[2]=0;
		minn = INT_MAX;
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(c[0] == n / 2 && c[1] == n/2)
		continue;
	    	b[i][1] = max(a[i][1],a[i][2]);
	    	b[i][2] = min(a[i][1],a[i][2]);
	    if(c[1] <= n/2 && c[2] <= n/2){
	    	cnt += b[i][1];
	    	minn=min(minn,b[i][1]);
	    if(a[i][1] > a[i][2]) c[1]++;
	    if(a[i][2] > a[i][1]) c[2]++;
		}
		else if(c[1] == n/2 && a[i][1] > a[i][2]){
			if(b[i][1] > minn)
			cnt = cnt - minn + b[i][1];
			else if(b[i][1] < minn && c[2] <= n/2){
			cnt += b[i][2];
			c[2]++;
		}
		}
	}
	cout << cnt;
	}
}
