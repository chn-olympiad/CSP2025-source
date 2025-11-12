#include<bits/stdc++.h>
using namespace std;
long long b[1000001];
char a[1000001];
char c[1000001];
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	int k = 0;
	scanf("%s",a + 1);
	while(1){
		if((a[k + 1] - '0' >= 49&&a[k + 1] - '0' <= 74)||(a[k + 1] - '0' >= 0&&a[k + 1] - '0' <= 9)){
			k += 1;
		}
		else{
			break;
		}
	}
	for(long long i = 1;i <= k;i++){
		if(a[i] - '0' >= 0&&a[i] - '0' <= 9){
			b[a[i] - '0'] += 1;
		}
	}
	int h = 1;
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= b[i];j++){
			c[h] = i;
			h += 1;
		}
	}
	cout << c;
	return 0;
} 
