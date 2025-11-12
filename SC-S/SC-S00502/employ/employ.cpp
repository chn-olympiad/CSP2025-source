#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>s[i];
	}
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	long long ans=0;
	for(int i=1; i<=n; i++){
		if(c[i]!=0){
			ans++;
		}
	}
	long long res=1;
	for(int i=1; i<=m; i++){
		res*=ans;
		res%=998244353;
		ans--;
	}
	cout<<res;
	return 0;
}