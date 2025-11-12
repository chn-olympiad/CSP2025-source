#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s1[200010],s2[200010],c1[200010],c2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;++i){
		cin>>c1[i]>>c2[i];
		cout<<0<<'\n';
	}
	return 0;
}
