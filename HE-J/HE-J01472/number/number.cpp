#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
char s[1000005];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int k = 1;
	cin >> s;
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[k++] = s[i] - '0';
		}
	}
	sort(a+1, a+k, cmp);
	for(int i = 1;i < k; i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
