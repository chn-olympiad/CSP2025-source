#include<bits/stdc++.h>
using namespace std;
string a;
const int N = 1e6 + 5;
int b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int g = 0;
	for(int i = 0;;i++){
		g = i;
		if(a[i] >= 'a'&&a[i] <='z'||a[i] >='0'&&a[i] <= '9'){
		}
		else{
			break;
		}
	}
	int ling = 0;
	for(int i = 0;i < g;i++){
		
		if(a[i] >= '0'&&a[i] <= '9'){
			b[ling] = a[i] - '0';
			ling++;
		}
		
	}
	sort(b + 0,b + ling);
	for(int i = ling - 1;i >= 0;i--){
			cout << b[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	
} 
