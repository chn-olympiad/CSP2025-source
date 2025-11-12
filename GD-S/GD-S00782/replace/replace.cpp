#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
const int maxn=2e5+10;
int n,q;
string s[maxn][3],t[maxn][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
