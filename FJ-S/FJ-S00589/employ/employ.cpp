#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],c[505],sum;
int ans=1;
bool b[505];
string s;
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) sum++;
	}
	if(m+sum>n){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	
	cout<<ans;
	return 0;
}
