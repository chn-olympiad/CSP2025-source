#include <bits/stdc++.h>
using namespace std;
bool df(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int p = n*m;
	int a[p+1];
	for(int i = 1;i <= p;i++){
		cin >> a[i];
	}
	int s = a[1];
	sort(a+1,a+p+1,df);
	int n1 = 0;
	int m1 = 1;
	int o = 0;
	for(int i = 1;i <= p;i++){
		if(n1+1 == n+1 && o == 0){
			m1 = m1 + 1;
			n1 = n;
			o = 1;
		}else if(n1-1 == 0 && o == 1){
			m1 = m1 + 1;
			n1 = 1;
			o = 0;
		}else if(o == 0){
			n1 = n1 + 1;
		}else{
			n1 = n1 - 1;
		}
		if(a[i] == s){
			break;
		}
	}
	cout << m1 << " " << n1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
