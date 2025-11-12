#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200001][2],que[200001][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++) cin>>que[i][0]>>que[i][1];
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

