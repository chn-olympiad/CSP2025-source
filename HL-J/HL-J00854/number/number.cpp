#include<iostream>
using namespace std;
int a[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char n;
	for(int i = 0;i <= 9;i++){
		a[i] = 0;
	}
	while(cin >> n){
		if(n == '0'){
			a[0]++;
		}else if(n == '1'){
			a[1]++;
		}else if(n == '2'){
			a[2]++;
		}else if(n == '3'){
			a[3]++;
		}else if(n == '4'){
			a[4]++;
		}else if(n == '5'){
			a[5]++;
		}else if(n == '6'){
			a[6]++;
		}else if(n == '7'){
			a[7]++;
		}else if(n == '8'){
			a[8]++;
		}else if(n == '9'){
			a[9]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= a[i];j++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
