#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],ans = 0,c,r;
	cin >> n >> m;
	int b = n*m;
	for(int i = 0; i < b; i++){
		cin >> a[i];
	}
	for(int i = 1; i < b; i++){
		if(a[0] < a[i]){
			ans++;
		}
	}
	c = ans / n + 1;
	if(c % 2 == 0){
		r = n - ans % n;
	}
	else{
		r = ans % n + 1;
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
