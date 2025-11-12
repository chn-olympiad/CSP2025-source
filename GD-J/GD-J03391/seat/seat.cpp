#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[15][15] = {0};
	int b[105];
	for(int i = 1; i <= n* m; i++){
		cin >> b[i];
	}
	int R = b[1];
	sort(b+1,b+(n*m)+1);
	int s = 0;
	for(int i = n * m; i >= 1; i--){
		if(b[i] == R){
			s = i; 
		}
	}
	s = (n*m) - s + 1;
	int p ;
	cout << s << endl;
	if(s / n == 0){
		cout << s/n << ' ';
		 p = s/n;
	}else{
		cout << s/n+1 << ' ';
		 p = s/n+1;
	}
	if(p % 2 ==0){
		int ss = s - (p-1) * n;
		cout << (n - ss) + 1;
	}else{
		int ss = s - (p-1) * n;
		cout << ss;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
