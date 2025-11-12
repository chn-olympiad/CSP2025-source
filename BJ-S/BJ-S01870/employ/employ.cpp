#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int c[505];
string s;
long long A(int x,int y){
	long long res=1;
	for(int i=1;i<=y;i++){
		res=res*(n+1-i);
		res%=mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	long long ans=0;
	for(int i=m;i<=n;i++){
		ans+=A(n,i);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
