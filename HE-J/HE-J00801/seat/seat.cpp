#include<bits/stdc++.h>
using namespace std;
int a[105],a1[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int nm = n*m; 
	for(int i = 1 ; i <= nm ; i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1,a+nm+1);
	int linshi = 1;
	for(int i = nm ; i >= 1 ; i--){
		a1[linshi] = a[i];
		linshi++;
	}
	for(int i = 1 ; i <= nm; i++){
		if(a1[i] == r){
			int b = i % 3 + 1;
			int c = i / m + 1;
			cout << b << ' ' << c; 
		}
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}
