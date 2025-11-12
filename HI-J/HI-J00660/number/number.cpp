#include <bits/stdc++.h>
using namespace std;
string a[100000],sum = 0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string n;
	cin >>n;
	for£¨int i = 1; i<= 10;i++){
		if (n[i] == 1 || n[i] == 2|| n[i] == 3 || n[i] == 4 || n[i] == 5 || n[i] == 6 || n[i] == 7 || n[i] == 8 || n[i] == 9){
			n[i] =a[i];
			sum++;
		}
	}
	sort(a + 1,a + n + 1);
	string num;
	for(int i = 1;i <= sum;i++){
		num += a[i]; 
	}
	cout << sum;
	return 0;
} 
