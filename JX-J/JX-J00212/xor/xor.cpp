#include <bits/stdc++.h>
using namespace std;
int a,b,c[114514];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b>>c[0]>>c[1];
	if(c[0]==c[1]) cout<<0;
	else if(c[0]==0) cout<<c[1];
	else cout<<c[0];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
