#include <bits/stdc++.h>
using namespace std;
int c,r,n,a[110];
int Rx,Ry,mn[11][11],Rc,Rxb,sum,k;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> c >> r;
	n = c * r;
	for (int i = 1;i <= n;i += 1){
		cin >> a[i];
		if (i == 1){
			Rc = a[i];
		}
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i <= n;i += 1){
		if (a[i] == Rc){
			Rxb = i;
			break;
		}
	}
	for (int i = 1;i <= r;i += 1){
		sum += c;
		if (sum >= Rxb){
			Ry = i;
			int tmp = Rxb % c;
			if (Rxb % c == 0){
				tmp == c;
			}
			if (Ry % 2 == 1){
				Rx = tmp;
			}
			else{
				Rx = c - tmp + 1; 
			}
			break;
		}
	}
	cout << Ry << ' ' << Rx;
	return 0;
}

