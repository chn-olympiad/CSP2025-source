#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	int n,m,b;
	string a;
	cin>>n>>m;
	int mi=10000;
	cin>>a;
	for (int i=1;i<=n;i++){
		cin>>b;
		if (b<mi) mi=b;
	}
	cout<<mi;
	return 0;
}
//QwQ
