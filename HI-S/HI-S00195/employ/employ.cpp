#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	string s[510];
	int c[510];
	for (int i = 1;i <= n;i++){
		cin >> s[i];
	}
	for (int i = 1;i <= n;i++){
		cin >> c[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
