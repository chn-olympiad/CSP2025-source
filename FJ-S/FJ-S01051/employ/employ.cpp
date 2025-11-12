#include<bits/stdc++.h>
using namespace std;
int c[502];
char s[502];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool f=1;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(s[i]!='1') f=0;
		else cnt++;
	}
	for(int i=0;i<m;i++){
		cin>>c[i];
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(f){
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
	}
	return 0;
}
