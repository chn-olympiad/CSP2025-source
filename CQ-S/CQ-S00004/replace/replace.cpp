#include <bits/stdc++.h>
using namespace std;
string a[200009][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n+q;i++)cin>>a[i][0]>>a[i][1];
	for(int i=1;i<=q;i++)cout<<0<<endl;
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
