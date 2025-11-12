#include<bits/stdc++.h>
using namespace std;

int main (){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	int n;
	cin >> n;
	if(n <= 2){
		cout << 0;
	}else{
		int ans = 0,maxx = -114514;
		for(int i = 1;i <= n;i ++ ){
			int x;
			cin >> x;
			ans += x;
			maxx = max(maxx,x);
		}
		if(ans > maxx * 2){
			cout <<1;
		}else {
			cout <<0;
		}
	}
	return 0;
}
