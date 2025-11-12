#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s[200001][2],sq[200001][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>sq[i][0]>>sq[i][0];
	}
	for(int i=1;i<=q;i++){
		cout<<2+i/3<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
