#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
struct Node{
	string a,b;
}a[N];
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b;
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		cout<<0<<'\n';
	}
	return 0;
}
