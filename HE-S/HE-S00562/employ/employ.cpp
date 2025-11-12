#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int a[510],t[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>10){
		sort(a+1,a+n+1);
		int c=0,sm=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c>=a[i])c++;
			else sm++;
		}
		if(sm<m){
			cout<<0;
			return 0;
		}
		int ans=1;
		for(int i=2;i<=n;i++)ans=ans*i%p;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)t[i]=i;
	int ans=0;
	do{
		int c=0,sm=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c>=a[t[i]])c++;
			else sm++;
		}
		if(sm>=m)ans=(ans+1)%p;
	}while(next_permutation(t+1,t+n+1));
	cout<<ans;
	return 0;
}
