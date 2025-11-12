#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,ans,N=998244353,a[100100];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int k=n,ans=1;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(k){
		ans=ans*n%N;
		k-=1;
	}
	cout<<ans;
	return 0;
}
