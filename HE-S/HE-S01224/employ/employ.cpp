#include <bits/stdc++.h>
using namespace std;
int n,m,a[501];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m<=n) cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
