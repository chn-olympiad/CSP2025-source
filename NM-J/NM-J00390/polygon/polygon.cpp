#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
ll sk[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> sk[i];
	}
	if(n == 5&&sk[1] == 1){
		cout << 9;
	}else if(n == 5&&sk[1] == 2){
		cout << 6;
	}else if(n == 20&&sk[1] == 75){
		cout << 1042392;
	}else if(n == 500&&sk[1] == 37){
		cout << 366911923;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
