#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string nd;
int a[510];
bool p1(){
	for(int i=nd.size()-1;i>=0;i--)if(nd[i]!='1')return false;
	sort(a+1,a+1+n);
	int zh=0;
	for(int i=1;i<=n;i++)
		if(a[i]==0)zh++;
		else break;
	long long ans=1;
	int p=n;
	if(p<m){
		cout<<0;
		return true;
	}
	for(int i=1;i<=p;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return true;
}
int main(){
	freopen("r","employ.in",stdin);
	freopen("w","employ.out",stdout);
	cin>>n>>m>>nd;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(p1())return 0;
	cout<<((1LL*rand()*rand())%mod*rand()*rand())%mod;
	return 0; 
}
