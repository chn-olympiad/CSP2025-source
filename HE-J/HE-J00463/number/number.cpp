#include <bits/stdc++.h>
using namespace std;
int _[1000005];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(NULL);
	
	char c;
	int a=0;
	while(cin>>c)
		if(c>='0'&&c<='9') _[a]=c-'0', a++;
	sort(_, _+a);
	for(int i = a-1;i>=0;i--) cout<<_[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
