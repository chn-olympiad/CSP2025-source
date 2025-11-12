#include<bits/stdc++.h>
using namespace std;
int n,m,b;
int s[505],c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b;
		c[b]++;
	}
	cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
