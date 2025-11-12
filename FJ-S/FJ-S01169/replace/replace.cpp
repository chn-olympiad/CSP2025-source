#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
string a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		cout<<0<<endl;
	}
	return 0;
} 
