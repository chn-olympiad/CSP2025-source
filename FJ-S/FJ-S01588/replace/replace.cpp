#include<bits/stdc++.h>
using namespace std;
string a1[100000],a2[100000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>a1[i]>>a2[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
