#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,m;
string s;
vector<int> c;
ll ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x!=0)c.push_back(x);
	}
	int l=c.size();
	for(int i=0;i<m;i++){
		ans=ans*(l-i)%mod;
	}
	cout<<ans;
	return 0;
}
