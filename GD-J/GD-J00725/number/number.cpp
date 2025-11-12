#include <bits/stdc++.h>
using namespace std;
string yuan;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> yuan;
	int num = 0;
	for(int i = 0; i<yuan.length(); i++){
		if(yuan[i] >= 48 && yuan[i] <= 57){
			a[num] = (int(yuan[i]) - 48);
			num++;

		}
	}	
	sort(a,a+num);
	for(int i = num - 1; i>=0; i--){
		cout << a[i];
	}
	return 0;
} 


