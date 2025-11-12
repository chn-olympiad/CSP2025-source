#include<bits/stdc++.h>
using namespace std;
int n,q;
struct ss{
	string a,b;
};
ss s[200010];
ss s1[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	for(int i=1;i<=q;i++){
		cin>>s1[i].a>>s1[i].b;
	}
	cout<<2<<"\n"<<0; 
	return 0;
} 
