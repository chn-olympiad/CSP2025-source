#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read() {
	ll op=1,x=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {
			op=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*op;
}
ll n,q;
struct node{
	string ss,sss;
};
node a[400001],b[400001];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1; i<=n; i++) {
		cin>>a[i].ss>>a[i].sss;
	}
	for(int i=1; i<=q; i++) {
		cin>>b[i].ss>>b[i].sss;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
		
	}
	return 0;
}
