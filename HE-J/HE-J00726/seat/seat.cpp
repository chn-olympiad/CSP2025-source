#include<bits/stdc++.h>
using namespace std;

int a[110];
bool cmp (int a,int b){
	return a > b;
}
int s;
int main (){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i ++){
		cin >> a[i];
		if(i == 1){
			s = a[i];
		}
	}
	sort(a + 1,a + 1 + n * m,cmp);
	int ansi,sum = 1;
	for(int i = 1;i <= n * m;i ++ ){
		
		if(a[i] == s){
			ansi = i;
			break;
		}
		if(i % n == 0){
			sum ++;
		}
	}
	if(sum % 2 == 0){
		cout << sum << " " << m - (ansi%n-1);
	}else{
		if(ansi % n == 0){
			cout << sum << " " << n;
		}else{
			cout << sum << " " <<ansi % n;
		}
	}
	return 0;
}
