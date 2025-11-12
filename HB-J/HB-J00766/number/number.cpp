#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000010];
	char n[1000010],c;
	int b = 0;
	cin >> a;
	for(int i = 0; i <= 1000010; i++){
		if(a[i] >= '0' && a[i] <='9') {
			n[b] = a[i];
			b++;
		}
	}
	for(int i = 0; i < b; i++){
		for(int j = i+1; j <= b; j++){
			if(n[j] > n[i]){
				c = n[i];
				n[i] = n[j];
				n[j] = c;
			}
		}
	}
	cout << n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
