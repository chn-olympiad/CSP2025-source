#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=1,x,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x)cnt++;
	}
	if(cnt<m)cout<<0;
	else{
		for(int i=1;i<=x;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
