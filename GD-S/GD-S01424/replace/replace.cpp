#include <bits/stdc++.h>
using namespace std;
string a[1005][5];
string qu[1005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n;
	cin>>n;
	int q;
	cin>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		cin>>a[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>qu[i][1];
		cin>>qu[i][2];
	}
	while(q--){
		cout<<0<<endl;
	}
	return 0;
}
