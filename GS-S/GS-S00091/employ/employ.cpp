#include <bits/stdc++.h>
using namespace std;
string s;
long long n,m,idx=1;
int a[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			idx+=1;
		}
	}
	if(n==m){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans=ans%998244353;
	}
	if(idx!=1){
		ans*=(idx-1);
	}
	ans=ans%998244353;
	cout<<ans;
}
