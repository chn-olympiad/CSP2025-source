#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 200;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int tmp = a[1];
	sort(a + 1,a + n * m + 1);
	reverse(a + 1,a + n * m + 1);
	int l = 1,r = 1;
	bool up = 0,flag = 1;
	for(int i = 1;i <= m * n;i++){
		if(a[i] == tmp){
			cout << l << ' ' << r;
			return 0;
		}
		//cout << l << ' ' << r << endl;
		if((r == 1 || r == n) && i != 1 && flag){
			l++;
			up = !up;
			flag = 0;
		}
		else{
			if(up) r--;
			else r++;
			flag = 1;
		}
		
	}
	return 0; 
	
}
