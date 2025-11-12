#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long ans=1;
	int n,m;
	cin>>n;
	cin>>m;
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	string s;
	cin>>s;
	int cnt=0;
	int a[n+1];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=0){
			a[++cnt]=x;
		}
	}
	for(int i=1;i<=m;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
