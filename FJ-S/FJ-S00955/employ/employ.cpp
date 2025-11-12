#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],d[505],sd[505];
long long ans=1;
string asd;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]==0)sd[i+1]=sd[i]+1;
		else sd[i]=1;
	}cin>>asd;
	for(int i=1;i<=n;i++){
		a[i]=asd[i-1]-48;
	}for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	return 0;
}
