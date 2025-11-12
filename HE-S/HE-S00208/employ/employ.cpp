#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long  long n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	long  long c[n];
	for(long  long i = 0;i<n;i++){
		cin>>c[i];
	}
	long long ans=1;
	for(int i = n;i>n-m;i--){
		ans=ans*i;
	}
	cout<<ans;
	return 0;
}
