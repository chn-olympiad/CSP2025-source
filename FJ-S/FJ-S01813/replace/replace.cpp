#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		string a,b;
		cin>>a>>b;
		cout<<abs(b.size()-a.size());
	}
	return 0;
}
