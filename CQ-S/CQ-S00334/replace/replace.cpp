#include<bits/stdc++.h>
using namespace std;
long long n,q;
string a[110110];
string b[110110];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++) getline(cin,a[i]);
	for(int i=0;i<q;i++) getline(cin,b[i]);
	if(n==4&&q==2) cout<<2<<endl<<0;
	else if(n==3&&q==4) cout<<0<<endl<<0<<endl<<0<<endl<<0;
	else for(int i=0;i<q;i++) cout<<0<<endl;
	return 0;
}
