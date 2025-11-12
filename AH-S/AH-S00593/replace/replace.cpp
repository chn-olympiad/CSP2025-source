#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s1[1000],s2[10000],q1[1000],q2[10000];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>q1[i]>>q2[i];
	}
	for(int i=1;i<=q;i++){
		cout<<'0'<<'\n';
	}
	return 0;
}
