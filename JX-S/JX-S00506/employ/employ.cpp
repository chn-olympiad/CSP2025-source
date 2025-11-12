#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int cnt=0;
	bool f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f=0;
			cnt++;
		}
	}
	if(n-cnt<m){
		cout<<0;
		return 0;
	}
	if(f||m==n){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(c+1,c+n+1);
	
	return 0;
}
