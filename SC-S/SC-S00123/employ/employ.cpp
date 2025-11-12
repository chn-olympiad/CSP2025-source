#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1005],ans=1,n1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	string np;
	cin>>np;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)n1++;
	}if(n-n1<m){
		cout<<0;
		return 0;
	}for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}cout<<ans;
	return 0;
}