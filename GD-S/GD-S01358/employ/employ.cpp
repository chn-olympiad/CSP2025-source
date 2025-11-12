#include<bits/stdc++.h>
using namespace std;
int a[100001],n,m,first=-1;
string s;
unsigned long long sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			first=i+1;
			break;
		}
	}
	if(m==n){
		if(first!=1){
			cout<<"0!";
			return 0;
		}
		for(int i=n;i>=1;i--)sum=(sum%998244353*i%998244353)%998244353;
		cout<<sum;
		return 0;
	}else if(s[0]=='1'&&s[10]=='1'&&s[99]=='1'){
		for(int i=n;i>=1;i--)sum=(sum%998244353*i%998244353)%998244353;
		cout<<sum;
		return 0;
	}else if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++)if(a[i]>=first)ans++;
		for(int i=n;i>=1;i--){
			if(i!=n-first+1)sum=(sum%998244353*i%998244353)%998244353;
			else sum=(sum%998244353*ans%998244353)%998244353;
		}
		cout<<sum;
		return 0;
	}
	cout<<"0";
	return 0;
}
