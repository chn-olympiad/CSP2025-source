#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
	
	freopen("replace.in","r","std.in")
	freopen("replace.out","w","std.out")
	string n;
	int q;
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>n[i];
	}
	string x,y,z,s;
	while(q--){
		x=x+'0';
		y=y+'0';
		z=z+'0';
		s=x+y+z;
		s=s+'0';
	}
	cout<<s;
	
	return 0;
}
