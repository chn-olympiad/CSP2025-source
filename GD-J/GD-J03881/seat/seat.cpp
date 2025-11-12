#include <bits/stdc++.h>
using namespace std;
int num[108];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> num[i];
	}
	int pm = num[1];
	sort(num+1,num+n*m+1); 
	for(int i = n*m;i > 0;i--){
		if(num[i] == pm){
			pm = n*m-i+1;
			break;
		}
	}
	int y = pm/n;
	if(pm % n == 0){
		y--;
	}
	y++;
	int x = pm%n;
	if(pm % n == 0){
		x = n;
	}
	if(y % 2 == 0){
		x = n-x+1;
	}
	cout << y << ' ' << x;
	return 0;
}
