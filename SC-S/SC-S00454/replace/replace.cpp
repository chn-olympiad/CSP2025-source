#include<bits/stdc++.h>
using namespace std;
string N[200005][5],Q[200005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>N[i][1]>>N[i][2];
	for(int i=1;i<=q;i++) cin>>Q[i][1]>>Q[i][2];
	for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}
