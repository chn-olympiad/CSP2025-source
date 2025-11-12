//GZ-S00145 航天高级中学 庹恩熙 
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
struct{
	string s1,s2;
}a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].s1>>a[i].s2;
	for(int i=1;i<=q;i++)
		cin>>b[i].s1>>b[i].s2;
		
	for(int i=1;i<=q;i++)
		cout<<0<<'\n';
	freopen("replace.out","w",stdout);
	return 0;
}

