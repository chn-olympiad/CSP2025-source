#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100001][2];
string d[100001][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>d[i][1]>>d[i][2];
	}
	for(int i=1;i<=q;i++){
		cout<<i<<endl;
	}
	return 0;
}
