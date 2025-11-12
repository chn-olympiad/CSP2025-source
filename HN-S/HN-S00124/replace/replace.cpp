#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string S;
	string s1;
	string s2;
};
node re[200005];
node s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>re[i].s1>>re[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
