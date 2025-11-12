#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[520];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	int ans=0;
	for(int i=1;i<=m;i++){
		ans+=c[i];
	}
	cout<<ans;
	return 0;
} 
