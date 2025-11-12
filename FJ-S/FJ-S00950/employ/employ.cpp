#include<bits/stdc++.h>
#define ll long long
using std::sort;
using std::cin;
using std::cout;
using std::endl;
const int N=1e5+50;
ll n,m,ans,a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	::std::string s;
	cin>>s;
	int p=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)p--;
	} if(p<m){
		cout<<"0";
		return 0;
	}
	int k=1;
	for(int j=n;j>=1;j--){
		k=k*j;
		k%=998244353;
	}ans=k%998244353;
	cout<<ans;
	return 0;
}
