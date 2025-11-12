#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p=998244353;
int n,m;
ll ans=1,now=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ans=ans*now%p,now++;
		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

