#include<bits/stdc++.h>
using namespace std;
int a[505];
long long ans=1,mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k=1;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	while(a[k]==0 && k<=n){
		n--;
		k++;
	}
	for(int i=m;i<=n;i++) ans*=n,ans%=mod;
	cout<<ans;
	return 0;
}
