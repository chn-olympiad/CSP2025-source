#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],n = 0,b[20];
void mysort(int a[],int n){
	for(int i = 0;i < n;++i){
		++b[a[i]];
	}
	for(int i = 9;i >= 0;--i){
		if(b[i]){
			for(int j = 1;j <= b[i];++j){
				cout << i;
			}
		}
	}
}
int main(){	
	cin >> s;
	for(int i = 0;i < s.length();++i){
		if (s[i] >= '0' && s[i] <= '9'){
			a[n] = (int)(s[i] - '0');
			++n;
		}
	}
	mysort(a,n);
	return 0;
} 
