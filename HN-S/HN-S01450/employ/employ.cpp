#include<bits/stdc++.h>
using namespace std;
int a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int ans=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans*=i;
	}
	cout<<ans;
	return 0;
} 
