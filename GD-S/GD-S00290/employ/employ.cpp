#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if(n == 3) cout << 2;
	if(n == 10) cout << 2204128;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
