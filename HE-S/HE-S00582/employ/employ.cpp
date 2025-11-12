#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen2("employ.out","w",stdout);
	int n;
	int c[n];
	int m;
	int p[n];
	cin >> n >> m;
	int s[n];
	int num[n];
	int number = 0;
	for(int i = 0;i <= n;i++)
		num[i] = 0;
	for(int i = 1;i < n;i++){
		cin >> s[i];
		cin >> c[i];
		p[i] = i;
	}	
	for(int i = 0;i <= n;i++){
		if(c[i] == 0){
			num[i] = 1;
		}
		if(s[i] == 1 && p[i] != 0){
			if(c[i] == 1 && s[i] == 1 && num[i - 1] == 1)
				num[i] == 1;
	}
	if(s[i] > 1 && c[i == 1]){
		if(p[i - 2] == 1)
			p[i] == 1; 
	}
	}
	for(int i = 0;i <= n;i++)
		if(i == 1)
			number++;
	cout << number;
	return 0;
} 
