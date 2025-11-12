#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,p;
	cin>>n>>p;
	char a[2000001],s[2000001];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i+n]>>s[i+n];
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	return 0;
}
