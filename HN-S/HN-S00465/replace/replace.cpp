#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200001],s2[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		getline(cin,s1[i]);
	for(int i=1;i<=q;i++)
		getline(cin,s2[i]);
	for(int i=1;i<=q;i++) cout<<"0\n";
	return 0;
}
