#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("numder.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[10] = {};
	cin >> a;
	long long num = a.size();
	long long n = 0;
	for(int i = 0;i < num;i++){
		if((a[i] >= '1') && (a[i] <= '9')){
			b[int(a[i])]++;
		}
	}
	for(int i = '9';i >= '0';i--){
		for(int j = 1;j <= b[i];j++){
				cout << char(i);
		}		
	}
return 0;
}
