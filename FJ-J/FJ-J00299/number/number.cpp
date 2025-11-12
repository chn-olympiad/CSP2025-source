#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001],b,k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i = 0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[k] = int(s[i])-48;
			b++;
			k++;
		}
	}
	for(int i = 0;i<b;i++){
		for(int j = i+1;j<b;j++)
			if(a[i] < a[j]) swap(a[i],a[j]);
	}
	for(int i = 0;i<b;i++){
		cout << a[i];
	}
	return 0;
}
