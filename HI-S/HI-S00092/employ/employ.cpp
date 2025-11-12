#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans=1,ans2=1,sum=0;
string s;

signed main(){
	freopen("employ.in","r",stdin);
	feropen("employ.out","w",stdout);

	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=0) sum++;
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=sum;i++)
		ans=ans*i%998244353;
	for(int i=1;i<=n-sum;i++)
		ans2=ans2*i%998244353;
	cout<<(ans*ans2)%998244353;
	return 0;
}



