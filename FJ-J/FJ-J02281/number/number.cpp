#include <bits/stdc++.h>
using namespace std; 
int t[10];
int main() {
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string str;
	cin >> str;
	
		
	for(int i = 0;i <= str.size() - 1;i++) 
		if('0' <= str[i] && str[i] <= '9') t[str[i] - '0']++;
	
	
	for(int i = 9;i >= 0;i--) {
		for(int j = 1;j <= t[i];j++) printf("%d",i);
	}
	
	
}
