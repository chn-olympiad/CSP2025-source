//GZ-J00366 遵义市新蒲中学 杨子曦 
#include <bits/stdc++.h>
using namespace std;
int a[105];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t=1,tk;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) {
		cin >> a[i];
		tk = a[1];
		if(a[i] > a[1]){
			t++;
		}
	}
	int tm = (t + n - 1) / n;
	int tn = t % n;
	if(tm % 2 == 0){
		if(tn == 0){
			tn = 1;
		}else{
			tn = n + 1 - tn;
		}
	}else{
		if(tn == 0){
			tn = n;
		}
	}
	cout << tm << " " << tn;
	return 0;
}
