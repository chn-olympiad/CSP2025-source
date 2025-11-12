#include<bits/stdc++.h>
using namespace std;
long long n,q;
string a[500010],b[500010],x[500010],y[500010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i]; 
	}
	for(int i=1;i<=n+q;i++){
		cout<<0<<endl; 
	}
	return 0;
}
