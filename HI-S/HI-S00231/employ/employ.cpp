#include<bits/stdc++.h>
using namespace std;
long long a[10010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,m;
	string s;
	long long num=1;
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		num*=a[i];
	}
	cout<<num%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
