#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
string s[N][3],t[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		cout<<0<<endl;
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}