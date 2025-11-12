#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string q;
	cin>>q;
	string s=" ";
	s+=q;
	int da=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			da++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(da==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans=ans%998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	if(m==1){
		if(da<n){
			for(int i=1;i<=n;i++){
				ans*=i;
				ans=ans%998244353;
			}
			cout<<ans%998244353;
			return 0;
		}
	}else if(m==n){
		if(da!=0){
			cout<<0;
			return 0;
		}
	}
	return 0;
}
