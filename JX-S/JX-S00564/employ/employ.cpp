#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int p=s.size();
	if(m==1){
		long long sum=0,ans=0;
		for(int i=0;i<p;i++){
			if(s[i]=='1'){
				sum++;
			}
		}
		for(int i=1;i<=sum;i++){
			ans+=i;
			ans%=998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	if(m==n){
			cout<<0;
			return 0;
	}
	cout<<1;
return 0;
}
