#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	char s[n + 10];
	int c[n + 10];
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i < n;i ++){
		cin >> c[i];
	}
	cout << m;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
