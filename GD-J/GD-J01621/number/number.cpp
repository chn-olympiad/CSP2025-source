#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000007];
int n = 1;

bool cmp(int a, int b){
	return a > b;
} 

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	int p = s.size();
	while(p--){
		if(s[p] <= '9' && s[p] >= '0'){
				a[n] = s[p] - '0';
				n++;
		}
	} 
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n - 1; i++){
		cout << a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
