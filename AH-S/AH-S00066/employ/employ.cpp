#include<bits/stdc++.h>
using namespace std;
int a[1000+10];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n]*a[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

