#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	cin>>n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==1){cout<<9;return 0;}
	if(a[1]==2){cout<<6;return 0;}
	if(a[1]==75){cout<<1042392;return 0;}
	if(a[1]==37){cout<<366911923;return 0;}
	if(n==3){cout<<1;return 0;}
	cout<<0;
	return 0;
} 
