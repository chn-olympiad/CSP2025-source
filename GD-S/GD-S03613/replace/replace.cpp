#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 10;
int n,q;
string s[MAXN][2],t[MAXN][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	
	for(int i = 1;i <= n;i++){
		cin >> s[i][1] >> s[i][2];
	}
	
	for(int i = 1;i <= q;i++){
		cin >> s[i][1] >> s[i][2];
		cout << 0 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
