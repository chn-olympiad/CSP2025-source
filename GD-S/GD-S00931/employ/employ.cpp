#include<bits/stdc++.h>
using namespace std;

int n,m,c[520];
char s[520];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int ans=1;
	for(int i=1;i<=m;i++)
		ans*=i;
	cout<<ans;
	return 0;
}
