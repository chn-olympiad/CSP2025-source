#include <bits/stdc++.h>
using namespace std;

int n,m,N[505],sum;
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int u;
		cin>>u;
		N[u]++;
	}
	for(int i=0;i<=m;i++){
		if(N[i]!=0) sum++;
		if(N[i]>1) ans=ans*N[i];
	}
	for(int i=sum;i>1;i--){
		ans=i*ans;
	}
	cout<<ans%998244353;
	return 0;
}

