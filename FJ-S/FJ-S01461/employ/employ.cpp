#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	char a[n+10]={};
	long long b[n+10]={};
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	long long ans=1;
	for(int i=n;i>=1;i++){
		ans=ans*n;
	}
	ans=ans%998244353;
}
