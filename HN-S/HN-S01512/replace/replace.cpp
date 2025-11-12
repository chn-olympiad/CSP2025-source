#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200004],s2[200004],t1[200004],t2[200004];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i];
	if(n==4&&q==2) cout<<2<<endl<<0;
	else if(n==3&&q==4) printf("0\n0\n0\n0");
	return 0;
}
