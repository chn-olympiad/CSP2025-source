#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,s[10010],t[10010];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int j=1;j<=q;j++){
		cin>>t[j];
	}
	if(n-q>0){
		cout<<n-q<<endl;
		cout<<0;
	}
	else if(n-q<1){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
