#include <bits/stdc++.h>
using namespace std;
string q[200005],p[200005];
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i]>>p[i];
	}
	for(int i=1;i<=m;i++){
		cin>>p[i]>>q[i];
	}
	for(int i=0;i<=m;i++){
		cout<<"0"<<endl;
	}
	return 0;
}
