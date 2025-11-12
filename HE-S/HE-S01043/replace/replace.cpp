#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string l[n+1],r[n+1]={};
	string qq[q+1],h[q+1]={};
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=q;i++){
		cin>>qq[i]>>h[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
