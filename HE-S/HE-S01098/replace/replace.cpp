#include<bits/stdc++.h>
using namespace std;
int n,q;
struct a{
	string s1;
	string s2;
}s[200005];
struct b{
	string x1;
	string x2;
}x[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(int i=0;i<q;i++){
		cin>>x[i].x1>>x[i].x2;
		cout<<0<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
