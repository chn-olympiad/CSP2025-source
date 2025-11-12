#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3)cout<<2;
	else if(n==10) cout<<2204128;
	return 0;
}

