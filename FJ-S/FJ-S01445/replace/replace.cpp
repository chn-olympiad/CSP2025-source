#include<bits/stdc++.h>
using namespace std;
const long long N=5e6;
long long n,q;
string s[N+5],t[N+5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0; 
}
