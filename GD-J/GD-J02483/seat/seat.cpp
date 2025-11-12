#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int cnt = 1,curr;
	for(int i = 1;i <= (n * m);i++){
		int x;cin >> x;
		if(i == 1){
			curr = x;
			continue;
		}
		if(x>curr)cnt++;
	}
	//cout << cnt << endl;
	int c=1,r=1;
	bool flag = 0;
	for(int i = 1;i < cnt;i++){
		if(r == 1 && flag){
			c++;
			flag = 0;
			continue;
		}
		if(r == n && !flag){
			c++;
			flag = 1;
			continue;
		}
		if(flag)r--;
		if(!flag)r++;
	}
	cout << c << ' ' << r;
	return 0;
}
