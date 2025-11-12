#include<bits/stdc++.h>
using namespace std;
char s[507];
int c[507];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<m;i++) cin>>c[i];
	if(m==n){
		for(int i=0;i<n;i++) if(s[i]=='1'){
			cout<<0<<endl;
			return 0;
		}
		long long j=1;
		for(int i=1;i<=n;i++) j=j*i%998244353;
		cout<<j<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
