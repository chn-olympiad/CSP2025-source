#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define DB double
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string x;
	cin>>x;
	int c[505];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	LL ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
} 
