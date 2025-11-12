#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==0)cnt++;
	}
	if(cnt>m){
		cout<<"0";
	}else{
		long long ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
