#include<bits/stdc++.h>
using namespace std;

int n,m,r;
string s;
int a[1010],b[1010];
int main() {
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if(s[i]!=1) {
			r=1;
		} 
		b[i+1]=s[i]-'0';
	} 
	for(int i=1;i<=m;i++) { 
		cin>>a[i];
	}	
	if(r==1) {
		long long cnt=1;
		for(int i=n;i>=1;i--) {
			cnt=cnt*i;
			cout<<cnt%998244353<<endl;
		}
		printf("%lld",cnt);
		return 0;
	}

	return 0;
}
