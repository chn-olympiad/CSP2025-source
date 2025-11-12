#include <bits/stdc++.h>
using namespace std;
int c[105],n,m,ans,num = 0,p[10][10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n >>m;
	for (int i = 1;i <= m*n;i++){
        cin >> c[i];
    }
    int sum = c[1];
	sort(c + 1,c + n*m + 1);
    for (int i = n*m;i >= 1;i--){
    	if (c[i] == c[1]){
    		ans = i;
		}
	}
	ans = n*m - ans;
    for (int i = 1;i >= m;i++){
    	for (int j = 1;j >= n;j++){
    		if (sum == ans)
    		    cout << p[i][j];
		}
	}
	cout << ans;
	return 0;    
}
