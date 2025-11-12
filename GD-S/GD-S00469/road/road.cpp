#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,s = 0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 0;i < n;i ++){
		cin >> u >> v >> w;
		s += w;
	}
	cout << s;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
