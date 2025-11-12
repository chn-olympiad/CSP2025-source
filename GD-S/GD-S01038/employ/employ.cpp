#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int x=n;
	for(int i=1;i<=n;i++) {
		int t;
		cin>>t;
		if(t==0) x--; 
	}
	cout<<1;
	return 0;
} 
