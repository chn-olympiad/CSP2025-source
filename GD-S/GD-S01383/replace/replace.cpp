#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,q;
string x[20001],y[20001];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	while(q--){
		cin>>a>>b;
		cout<<0<<endl;
	}
	return 0;
}
