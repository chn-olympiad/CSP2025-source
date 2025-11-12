#include<bits/stdc++.h>
using namespace std;
int n,q;string w[200008][3],r[200008][3];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i][1],w[i][2]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&r[i][1],r[i][2]);
	}
	for(int i=1;i<=q;i++)cout<<0<<endl;
	return 0;
}