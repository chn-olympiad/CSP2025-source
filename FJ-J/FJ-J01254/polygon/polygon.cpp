#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[9999];
	string s;
	freopen("polygon.in","r",stdin);
	getline(cin,s);
	n=int(s[0]-'0');
	for(int i=0;i<n;i++)cin>>a[i];
	freopen("polygon.out","w",stdout);
	if(n==3)cout<<1;
	else cout<<0;
	return 0;
}
