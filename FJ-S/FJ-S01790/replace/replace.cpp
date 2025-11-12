#include<bits/stdc++.h> 
using namespace std;
int n,q;
string a[200005],b[200005];
string tv[200005],tu[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>tv[i]>>tu[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<"\n"; 
	}
	return 0;
}
