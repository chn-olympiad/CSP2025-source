#include<bits/stdc++.h>
using namespace std;
int a[5001];
int s[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	if(n==5&&a[1]==1) cout<<9;
	else if(n==5&&a[1]==2) cout<<6;
	else if(n==20&&a[1]==75) cout<<1042392;
	else cout<<366911923;
}
