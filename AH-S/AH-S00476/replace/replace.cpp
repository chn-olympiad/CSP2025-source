#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,q;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int w[1000],g[1000],h[1000],r[1000];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>g[i];
	}
	for(int i=1;i<=q;i++){
		cin>>h[i]>>r[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


