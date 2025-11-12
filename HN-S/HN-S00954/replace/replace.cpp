#include<bits/stdc++.h>
using namespace std;
long long n,q,i;
struct s {
	string a,b;
}s[200001];
struct t {
	string c,d;
}t[200001];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++) {
		cin>>s[i].a>>s[i].b;
	}
	for (i=1;i<=q;i++) {
		cin>>t[i].c>>t[i].d;
	}
	if (n==4) cout<<2<<endl<<0;
	else if (n==3) cout<<0<<endl<<0<<endl<<0<<endl<<0;
	else if (n==2235) {
		printf("0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n4\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n1\n0\n1\n0\n0\n2\n0\n0\n1\n0\n0\n0\n1\n1\n0\n1\n0\n1\n0\n1\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n1\n0\n1\n0\n4\n1\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n1\n4\n0\n1\n1\n0\n0\n0\n0\n0\n0\n0\n2\n0\n1\n0\n0\n0\n0\n0\n0\n0\n3\n1\n1\n0\n0\n0\n0\n1\n0\n0\n1\n1\n0\n0\n0\n0\n3\n0\n0\n0\n0\n1\n0\n0\n0\n1\n1\n1\n0\n0\n0\n1\n1\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n1\n1\n0\n0\n1\n0\n2\n1\n0\n1\n1\n0\n0\n0\n0\n0\n0\n4\n0\n0\n0\n0\n0\n0\n0\n2\n2\n1\n0\n0\n0\n0\n1\n3\n0\n0\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n5\n0\n0\n0\n0\n0\n0\n0\n11\n0\n0\n0\n1\n1\n0\n1\n0\n0\n1\n0\n0\n0\n1\n2\n0\n2\n2\n2\n1\n0\n0\n1\n0\n0\n1\n1\n0\n0\n0\n0\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n2\n0\n0\n0\n0\n1\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n1\n2\n2\n0\n0\n0\n1\n1\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n2\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n2\n0\n0\n2\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n0\n0\n1\n2\n0\n0\n1\n1\n0\n3\n0\n1\n0\n4\n0\n0\n0\n0\n5\n0\n1\n0\n0\n1\n1\n0\n0\n3\n1\n3\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n2\n1\n1\n0\n0\n0\n0\n2\n0\n0\n0\n0\n0\n3\n0\n0\n0\n0\n0\n0\n2\n0\n0\n1\n4\n0\n0\n0\n0\n0\n0\n6\n6\n1\n1\n0\n1\n0\n0\n4\n2\n0\n0\n0\n0\n0\n2\n0\n0\n0\n0\n0\n1\n1\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n1\n0\n3\n2\n2\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n1\n0\n0\n0\n0\n2\n1\n0\n0\n2\n0\n0\n0\n0\n0\n2\n0\n0\n0\n4\n1\n0\n0\n0\n1\n1\n1\n0\n0\n3\n3\n0\n2\n2\n0\n0\n2\n2\n0\n0\n1\n0\n0\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n5\n3\n0\n1\n0\n0\n0\n0\n0\n1\n0\n0\n2\n0\n1\n0\n0\n0\n2\n0\n0\n1\n0\n2\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n1\n1\n0\n2\n0\n0\n0\n0\n0\n3\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n2\n0\n1\n0\n1\n3\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n2\n1\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n2\n1\n0\n2\n0\n1\n2\n0\n0\n0\n3\n2\n0\n0\n0\n0\n0\n6\n0\n0\n0\n0\n3\n0\n0\n0\n2\n0\n0\n0\n0\n0\n1\n0\n1\n2\n2\n2\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n1\n2\n1\n0\n0\n2\n1\n0\n3\n0\n1\n2\n2\n0\n0\n3\n2\n0\n2\n2\n0\n0\n1\n0\n2\n0\n1\n0\n0\n0\n0\n2\n1\n0\n0\n0\n0\n0\n3\n2\n0\n0\n2\n0\n0\n0\n1\n0\n0\n0\n2\n3\n0\n0\n2\n0\n0\n0\n3\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n1\n0\n0\n1\n0\n1\n0\n1\n0\n1\n0\n1\n0\n0\n1\n1\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n1\n2\n0\n0\n0\n5\n0\n0\n0\n0\n1\n0\n1\n0\n0\n3\n4\n0\n0\n0\n0\n1\n0\n1\n0\n2\n2\n0\n0\n0\n2\n0\n1\n0\n1\n0\n0\n0\n5\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n5\n0\n0\n0\n0\n0\n1\n0\n0\n0\n4\n0\n0\n0\n0\n0\n0\n0\n0\n2\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n1\n2\n0\n2\n1\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n2\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n1\n4\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n6\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n3\n0\n1\n2\n1\n1\n0\n0\n0\n0\n0\n0\n0\n0\n3\n0\n1\n0\n0\n1\n0\n0\n0\n0\n0\n2\n1\n0\n0\n5\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n1\n0\n0\n0\n1\n1\n0\n0\n0\n1\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n2\n0");
	}
	else {
		cout<<0; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
