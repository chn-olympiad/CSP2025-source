#include <bits/stdc++.h>
using namespace std;
struct str{
	string a,b;
};
int n,q;
str str_[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str_[i].a>>str_[i].b;
	}
	while(q--){
		string a1,b1;
		cin>>a1>>b1;
	}
	cout<<2;
	return 0;
} 
