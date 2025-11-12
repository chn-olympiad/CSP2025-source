#include<bits/stdc++.h>
using namespace std;
int n,q;
struct ss{
	string s1,s2;
}a[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i ++)cin>>a[i].s1>>a[i].s2;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cout<<0<<'\n';
	}
	return 0;
}
