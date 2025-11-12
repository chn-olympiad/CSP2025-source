#include <bits/stdc++.h>
using namespace std;
int a,b,c[10000000];
int main() {

	//cin>>n;
	freopen("xor.in","r","stdin");
	freopen ("xor.out","w","stdout");
	cin>>a>>b;
	for(int i=1; i<=a; i++) cin>>c[i];
	if(b==0) cout<<a/2;
	return 0;
}
