#include<bits/stdc++.h>
using namespace std;
int n,m,num,l,h; 
int a[110],f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1,a + n * m + 1);
	for (int i = n * m;i >= 1;i--){
		f++;
		if (r == a[i]){
			num = f;
			break;
		}
	}
	if (num % n == 0)	l = num / n;
	else	l = num / n + 1;
	if (l % 2 == 0)	h = n - (num % n) + 1;
	else{
		if (num % n == 0)	h = n;
		else	h = num % n;
	}
	cout << l << " " << h;
	return 0;
}

