#include <bits/stdc++.h>
using namespace std;

int a[110],idx;

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int user;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	user = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++){
		if(a[i] == user){
			idx = i;
			break;
		}
	}
	if(idx%n == 0){
		int h = idx/n;
		if(h%2 == 0){
			cout << h << " " << 1;
		}else{
			cout << h << " " << n;
		}
	}else{
		int h = idx/n + 1;
		int l = idx%n;
		if(h%2 == 0){
			int ll = n - l + 1;
			cout << h << " " << ll;
		}else{
			cout << h << " " << l;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
