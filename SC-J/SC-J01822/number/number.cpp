#include<iostream>
using namespace std;
char c[1000010];
int a[11];
int len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	for(int i = 1;i <= sizeof(c);i++){
		if(c[i] >= '0'&&c[i] <= '9'){
			a[c[i] - '0']++;
		}
	}
	
	bool flag = false;
	for(int i = 9;i >= 0;i--){
		if(a[i] > 0)flag = true;
	}
	if(!flag){
		cout << 0;
		return 0;
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= a[i];j++){
			cout << i;
		}
	}
	return 0;
}