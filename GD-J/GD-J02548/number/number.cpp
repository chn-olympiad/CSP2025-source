#include<iostream>
using namespace std;
int a[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(auto x:s)if(x>='0'&&x<='9')a[x-'0']++;
	for(int i=9;i>=0;i--)while(a[i]--)printf("%d", i);
	return 0;
}
