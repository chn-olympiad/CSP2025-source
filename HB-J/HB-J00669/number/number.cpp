#include <bits/stdc++.h>
using namespace std;
char s[1000000];
int k,a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i = 0;i < 1000000;i ++){
		cin >> s[i];
		if(s[i] <= '9' && s[i] >= '0'){
			a[k] = s[i]-48;
			k ++;
		}
	}
	for(int i = 0;i < k-1;i ++){
		if(a[i] < a[i+1]) swap(a[i],a[i+1]);
	}
	for(int i = 0;i < k;i ++){
		cout << a[i];
	}
	return 0;
}
