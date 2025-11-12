#include <bits/stdc++.h>
using namespace std;
int n,m;
struct adf{
	int id;
	int fen;
}a[105];
bool cmp(adf x,adf y){
	return x.fen>y.fen;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out" , "w", stdout);
	cin >> n >> m;
	for (int i = 1;i<=n*m;i++){
		cin >> a[i].fen;
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int i = 0,j = 1,ans = 0;
	bool f = 0,fl = 1;
	while(1){
		ans++;
		if (i==n&&fl == 1){
			j++;
			f= 1;
			fl = 0;
			if (a[ans].id==1){
				cout << j << " " << i;
				break;
			}
			continue;
		}
		else if (f == 1){
			if (i==1){
				j++;
				f = 0;
				if (a[ans].id==1){
					cout << j << " " << i;
					break;
				}
				continue;
			}
			i--;
			fl = 1;
			if (a[ans].id==1){
				cout << j << " " << i;
				break;
			}
		}
		else{
			i++;
			if (a[ans].id==1){
				cout << j << " " << i;
				break;
			}
		
		}
	}
	
	return 0;
}

