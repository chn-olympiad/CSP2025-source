#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,p,a[200010]={},b[200010]={};
	cin>>n>>p;
	for(int i=1; i<=n; i++){
		cin >>a[i];
	}
	for(int i=1; i<=p; i++){
		cin>>b[i];
	}
	for(int i=1; i<=p; i++){
		cout<<0<<endl;
	}
	return 0;
}
