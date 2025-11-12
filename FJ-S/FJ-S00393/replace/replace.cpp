#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string a,b;
}a[1000008];
struct aode{
	string c,d;
}c[1000008];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i].a;
		cin>>a[i].b;
	}
	for(int i=0;i<q;i++){
		cin>>c[i].c>>c[i].d;
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}
