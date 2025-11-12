#include <bits/stdc++.h>
using namespace std;
int n,m,s[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> s[i];
	int a = s[1],l;
	sort(s + 1,s + n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++){
		if (s[i] == a) l = i;
	}
	//cout << a << l;
	int x = (l - 1) / n + 1,y;
	if (x & 1){
		y = l % n == 0 ? n : l % n;
	}
	else{
		y = n - (l % n == 0 ? n : l % n) + 1;
	}
	cout << x << " " << y;
	return 0;
} 
