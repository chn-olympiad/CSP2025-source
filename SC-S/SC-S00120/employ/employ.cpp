#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,nx[520]={},dp[520]={},a[520]={},b[520]={},ts[520]={},t=1,t_=0;
	cin>>n>>m;
	char c;
	bool b_;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='1'){
			b_=0;
			t_++;
		}
		b[i]=c-'0'+1;
		b[i]%=2;
		a[i]=b[i]+a[i-1];
	}
	if(b_==1||t_<=m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>nx[i];
	nx[n+1]=INT_MAX; 
	sort(nx+1,nx+n+1);
	for(int i=1;i<=n;i++){
		while(nx[t]<a[i]) t++;
		ts[i]=t;
	}
	vector<int>v;
	for(int i=n;i>0;i--){
		v.push_back(nx[i]);
	}
	int ans=1;
	while(!v.empty()){
		if(v.back()!=0) ans*=v.back();
		ans%=998244353;
		v.pop_back();
		for(int i=0;i<v.size();i++) v[i]--;
	}
	cout<<(ans*m)%998244353;
	return 0;
}