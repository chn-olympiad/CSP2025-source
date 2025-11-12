#include <bits/stdc++.h>
using namespace std;
int m,n;
int t[1000];

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int s = n*m;
	for(int i=1;i<=s;i++){
		cin >> t[i];
	}
	int a = t[1],vi; 
	sort(t+1,t+s+1,cmp);
	for(int i=1;i<=s;i++){
		if(t[i] == a){
			vi = i;
			break;
		}
	}
	int x,y;
	x = (vi - 1)/ m + 1;
	if(x % 2 == 0){
		if(vi % m == 0){
			y = 1;
		}
		else{
			y = m + 1 - vi % m;
		}
	}
	else if(vi % m == 0){
		y = m; 
	}
	else{
		y = vi % m;
	}
	cout << x << ' ' << y;
	return 0;
}
