#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],score,r,c,idx,delta;
bool cmp(int x,int y){return x > y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;++i) cin >> a[i];
	score = a[1]; r = 1,c = 1,idx = 1,delta = 1;
	sort(a + 1,a + n * m + 1,cmp);
	while(a[idx] != score){
		idx++;
		if(delta > 0 && r < n) r += delta;
		else if(delta < 0 && r > 1) r += delta;
		else if(delta > 0 && r == n){
			c++;
			delta = -1;
		}
		else if(delta < 0 && r == 1){
			c++;
			delta = 1;
		}
	}
	cout << c << " " << r << "\n";
	return 0;
} 
