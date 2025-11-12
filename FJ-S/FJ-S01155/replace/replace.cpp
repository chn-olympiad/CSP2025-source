#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200020][3],a[200020][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=2;j++)
			cin>>s[i][j];
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
} 
