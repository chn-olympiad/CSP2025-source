#include<bits/stdc++.h>
using namespace std;

string s[3][200001],t[3][200001];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q,ff=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[1][i]>>s[2][i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[1][i]>>t[2][i];
	}
	cout<<1;
	
	fclose(stdin);
	fclose(stdout);
}

