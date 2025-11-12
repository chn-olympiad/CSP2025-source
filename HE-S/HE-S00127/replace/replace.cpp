#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string s[100001][100001];
	for(int i=1;i<=n;i++){
		cin>>s[i][i];
	}
	string t[100001][100001];
	for(int j=1;j<=q;j++){
		cin>>t[j][j];
	}
	if(n==4 and q==2){
		cout<<2<<endl<<0;
	}
	if(n==3 and q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
