#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5,M = 1e6 + 5;
char a[M];
long long b[N],cnt = 1;
int cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int l = strlen(a);
	for(int i = 0;i < l;i++){
		if(a[i] - '0' >= 0 && a[i] - '0' <= 9){
			b[cnt] = a[i] - '0';
			cnt++;
		}
	}
	sort(b + 1,b + 1 + cnt,cmp);
	if(b[1] == 0){
		cout << 0;
	}
	else{
		for(int i = 1;i < cnt;i++){
			cout << b[i];
		}
	}
	return 0;
}
