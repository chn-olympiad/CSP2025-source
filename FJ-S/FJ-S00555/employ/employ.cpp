#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
long long ans=1;
int a[10086];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int k=n,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) k--;
		if(a[i]>0 && s[i]=='1') cnt++;
	}	
	if(m==n){
		cout<<0;
		return 0;
	}
	if(m==1){
		if(cnt==0) cout<<0;
		else{
			for(int i=n-1;i>1;i--){
				ans*=i%998244353;
				ans%=998244353;
			}
			ans*=cnt;
			ans%=998244353;
			cout<<ans;
		}
		return 0;
	}
	for(int i=k;i>1;i--){
		ans*=i%998244353;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
