#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int a[N];
string s;
int f = 1;
bool cmp(int a, int b); 
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i <= s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[f++] = s[i] - 48;
		}
	} 
	f--;
	sort(a + 1, a + f + 1, cmp);
	for(int i = 1; i <= f; i++){
		printf("%d", a[i]);
	} 
	printf("\n");
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
bool cmp(int a, int b){
	return a > b;
}