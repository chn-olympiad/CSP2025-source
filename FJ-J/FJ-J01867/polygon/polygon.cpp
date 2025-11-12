#include<bits/stdc++.h>
using namespace std;
int a[5016];
int sum = 0;
int cnt = 1;
int flag = true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n ;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	for(int i = 1; i <= n; i++) {
		if(a[i] == 1) flag = true;
		else {
			flag = false;
			break;
		}
	}
	sort(a + 1 , a + n + 1);
	if(flag) {
		for(int i = 1; i <= n; i++) {
			cnt = cnt * 2;
		}
		cout << cnt - n - n * (n - 1) / 2 - 1 << endl;
		return 0;
	}
	else if(n < 3) cout << 0 << endl;
	else if(n == 3) {
		if(a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	else if(n == 4) {
		if(a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]) sum++;
		if(a[1] + a[2] > a[4] && a[1] + a[4] > a[2] && a[2] + a[4] > a[1]) sum++;
		if(a[1] + a[3] > a[4] && a[1] + a[4] > a[3] && a[3] + a[4] > a[1]) sum++;
		if(a[3] + a[2] > a[4] && a[4] + a[3] > a[2] && a[2] + a[4] > a[3]) sum++;
		if(a[1] + a[2] + a[3] + a[4] > 2 * a[4]) sum++;
	}
	else if(n == 5) {
		if(a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]) { 
		    sum++;
		}
		if(a[1] + a[2] > a[4] && a[1] + a[4] > a[2] && a[2] + a[4] > a[1]) { 
		    sum++;
		}
		if(a[1] + a[2] > a[5] && a[1] + a[5] > a[2] && a[2] + a[5] > a[1]) { 
		    sum++;
		}
		if(a[1] + a[3] > a[4] && a[1] + a[4] > a[3] && a[3] + a[4] > a[1]) { 
		    sum++;
		}
		if(a[1] + a[3] > a[5] && a[1] + a[5] > a[3] && a[3] + a[5] > a[1]) { 
		    sum++;
		}
		if(a[1] + a[5] > a[4] && a[1] + a[4] > a[5] && a[5] + a[4] > a[1]) { 
		    sum++;
		}
		if(a[3] + a[2] > a[4] && a[4] + a[3] > a[2] && a[2] + a[4] > a[3]) { 
		    sum++;
		}
		if(a[3] + a[2] > a[5] && a[5] + a[3] > a[2] && a[2] + a[5] > a[3]) { 
		    sum++;
		}
		if(a[5] + a[2] > a[4] && a[4] + a[5] > a[2] && a[2] + a[4] > a[5]) { 
		    sum++;
		}
		if(a[3] + a[4] > a[5] && a[4] + a[5] > a[3] && a[3] + a[5] > a[4]) { 
		    sum++;
		}
		if(a[1] + a[2] + a[3] + a[4] > 2 * a[4]) { 
		    sum++;
		}
		if(a[1] + a[2] + a[3] + a[5] > 2 * a[5]) { 
		    sum++;
		}
		if(a[5] + a[2] + a[3] + a[4] > 2 * a[5]) { 
		    sum++;
		}
		if(a[1] + a[5] + a[3] + a[4] > 2 * a[5]) { 
		    sum++;
		}
		if(a[1] + a[5] + a[2] + a[4] > 2 * a[5]) { 
		    sum++;
		}
		if(a[1] + a[2] + a[3] + a[4] + a[5] > 2 * a[5]) { 
		    sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
