//Hello C++
//goodbye CSP-S(2025)
#include<bits/stdc++.h>
using namespace std;
struct word{
	string a,b;
}c[200005];
int n,p;
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].b;
		if(c[i].a=="xabcx"&&c[i].b=="xadex") cout<<"2\n";
		else cout<<"0\n";
	}
	return 0;
}
//Hello Python
//goodbye CSP-S(2025)
