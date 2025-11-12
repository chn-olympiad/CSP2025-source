#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int ui[105] = {},s,ans = 0,re;
	int n,m;
		cin >> n >> m;
	cin >> re;
	for(int i = 1;i < n * m;i++){
		cin >> s;
		ui[s]++;
	}
	for(int i = 101;i > re;i--){
		ans += ui[i];
	}
	if(ans/n %2 ==0){
		cout << ans / n + 1 << " " << ans - ans/n * n+1;
	}else{
		cout << ans / n + 1 << " " << n - (ans - ans/n * n);
	}
	return 0;
} 
