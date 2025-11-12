#include<bits/stdc++.h>
using namespace std;
long long n,m,c[1000050],ans=1,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=0;i<n;i++){
		cin>>c[i];
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		ans*=(i+1);
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}


