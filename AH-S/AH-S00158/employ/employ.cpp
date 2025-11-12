//7.07 14.22 7.01 14.15  '11.15'    
#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[600];
int c[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		
	}
	sort(c+1,c+n+1);
	int d=0;
	for(int i=0;i<n;i++){
		d+=(s[i]-'0');
	}
	if(d<m){
		cout<<0;
		return 0;
	}
	if(d==n){
		long long ans=1;
		for(int i=1;i<n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	return 0;
}
