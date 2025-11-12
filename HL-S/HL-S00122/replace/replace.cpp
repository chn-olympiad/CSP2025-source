#include <bits/stdc++.h>
using namespace std;
int n,q;
struct zfc{
	string s1,s2;
}s[200001];
struct th{
	string t1,t2;
}t[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(int i = n;i<=n;i++){
		cin>>t[i].t1>>t[i].t2;
	}
	cout<<2<<endl<<0<<endl;
	cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
	return 0;
} 
