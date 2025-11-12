#include<bits/stdc++.h>
using namespace std;

long long n,m,ans=1,y;
long long mod=998244353;
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')
			y++;
	}
	if(y<m){
		cout<<0;
		return 0;
	}
	long long a[n+5],b=n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			b--;
			continue;
		}
	}
	if(b<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		ans=(ans*b)%mod;
		b--;
	}
	cout<<ans;
	return 0;
}
