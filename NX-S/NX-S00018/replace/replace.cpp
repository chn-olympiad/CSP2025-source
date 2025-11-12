#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string a[100000];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		string a1;
		string b1;
		cin>>a1>>b1;
		if(a1.size()!=b1.size()){
			cout<<0<<endl;
		}
	}
	return 0;
}
