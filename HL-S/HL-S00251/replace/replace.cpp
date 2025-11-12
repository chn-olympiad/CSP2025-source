#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s,x,y,z;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q;j++){
			cin>>s>>x>>y>>z;
		}
	}
	swap(x,y,z);
	cout<<x;
	return 0;
}
