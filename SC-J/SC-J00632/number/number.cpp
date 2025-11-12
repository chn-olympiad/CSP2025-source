#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[1000005] , p = 1;
int comp(int x , int y){
	return x > y;
}
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> a;
	int n = strlen(a);
	for(int i = 0; i < n; i ++){
		if(int(a[i]) <= 57 && int(a[i] >= 48)){
			b[p] = int(a[i]) - 48;
			p ++;
		}
	}
	sort(b + 1 , b + 1 + n , comp);
	for(int i = 1; i < p; i ++){
		cout << b[i];
	}
	return 0;
 } 