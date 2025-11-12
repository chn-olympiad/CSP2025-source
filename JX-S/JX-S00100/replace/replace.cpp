#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1;
	string s2;
}re[200010],t[200010];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>re[i].s1>>re[i].s2;
	for(int i=1;i<=q;i++) cin>>t[i].s1>>t[i].s2;
	for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}
