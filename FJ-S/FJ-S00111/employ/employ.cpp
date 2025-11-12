#include<bits/stdc++.h>
using namespace std;

int c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int flag=1;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') flag=0;
		if(s[i]=='1') cnt++;
	}
	if(flag==1){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(m>cnt){
		cout<<0;
		return 0;
	}
	return 0;
}
