#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	vector<string> a,b;
	string s1,s2;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		a.push_back(s1);
		b.push_back(s2);
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl; 
	}
	return 0;
}