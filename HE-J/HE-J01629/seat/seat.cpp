#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 15;
int n,m;
int a[N * N];
int s;

bool cmp(int x,int y){
	return x > y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++){
		cin>>a[i];
	}
	s = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int x = 0,y = 0;
	for(int i = 1;i <= n * m;i++){
		if(a[i] == s){
			if(i % n == 0 && i >= n) y = i / n;
			else y = i / n + 1;
			if(y % 2 != 0){
				if(i % n != 0) x = i % n;
				else x = n;
			}else{
				if(i % n == 0) x = 1;
				else x = n - i % n + 1;
			}
		}
	}
	
	cout<<y<<" "<<x;
	return 0;
}
