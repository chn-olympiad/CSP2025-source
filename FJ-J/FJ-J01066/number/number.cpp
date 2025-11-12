#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000000];
	string b;
	int c=0;
	cin >> b;
	for(char d : b){
		if (d>='0'&&d<='9'){
			a[c]=d-'0';
			c++;
		}
	}
	sort(a,a+c);
	for(int i=c-1;i>=0;i--)cout << a[i];
	
	return 0;
}
