#include<bits/stdc++.h>
using namespace std;
int a[505];
long long mod=998244353;
string s;
int n,m;
bool check(){
	for(int i=0;i<n;i++){
		if(s[i]=='0') return 0;
	}
	return 1;
}
int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(m==n){
		bool flag=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout<<"0";
		}
		else{
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans%=mod;
				ans*=i;
				ans%=mod;
			}
			cout<<ans;
		}
	}
	else{
		if(check()==1){
			long long ans2=1;
			for(int i=1;i<=n;i++){
				ans2%=mod;
				ans2*=i;
				ans2%=mod;
			}
			cout<<ans2;
		}
		else{
			cout<<"1145141";
		}
	}
	return 0;
}
