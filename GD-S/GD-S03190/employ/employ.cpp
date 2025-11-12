#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[505];
	string x;
	cin>>n>>m>>x;
	ll ans=0;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0 or a[i]<=sum){sum++;
		//cout<<i<<' '<<a[i]<<endl;
		}
		if(a[i]!=0 and a[i]>sum)ans++;
	}
	ll c=1;
	if(ans==1)cout<<1;
	if(ans==2)cout<<2;
	if(ans>=3){
		for(int i=1;i<=ans;i++){
		c*=i;
		c%=998244353;
		}
		cout<<c;
	}
	
	
	return 0;
} 
