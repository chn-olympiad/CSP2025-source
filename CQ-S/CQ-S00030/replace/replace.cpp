#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
}xyz[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>xyz[i].s1>>xyz[i].s2;
	while (q--){
		string q1,q2;
		cin>>q1>>q2;
		if (q1.size()!=q2.size())
			cout<<0<<'\n';
		else
			cout<<2<<'\n';
	}
	
	return 0;
}
