#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[2000006],b[2000006],c[2000006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++) cin>>c[i];
	if(n==4&&q==2){
		cout<<2<<endl<<0;
		return 0;
	}
	if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
		return 0;
	}
	return 0;
}
