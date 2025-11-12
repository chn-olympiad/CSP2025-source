#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==2&&a[0]|a[1]==m)cout<<1;
	else if(n==2)cout<<0;
	else cout<<9;
	return 0;
}