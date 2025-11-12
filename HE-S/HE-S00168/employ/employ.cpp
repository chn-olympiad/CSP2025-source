#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[10005];
long long value=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=m;i<=n;i++){
		value*=i;
	}
	cout<<value%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
