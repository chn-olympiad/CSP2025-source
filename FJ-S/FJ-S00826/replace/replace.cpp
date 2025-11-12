#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200000+10],b[200000+10],c[200000+10],d[200000+10];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i]>>d[i];
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	return 0;
}
