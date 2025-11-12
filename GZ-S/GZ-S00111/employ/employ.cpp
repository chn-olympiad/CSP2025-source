//GZ-S00111 贵阳市第一中学  周熙原 
#include<bits/stdc++.h>
using namespace std;
int c[505];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	if(m==n){
		string s;
		cin>>s;
		bool t=1;
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(!c[i]) t=0;
		}
		for(int i=0;i<n;i++){
			if(s[i]=='0') t=0;
		}
		long long sum=1;
		for(int i=2;i<=n;i++){
			sum=((sum%998244353)*(i%998244353))%998244353;
		}
		if(t){
			cout<<sum;
			return 0;
		}
		cout<<0;
	}
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
			cin>>c[i];
		}
	bool t=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0') t=0;
	}
	if(t){
		long long sum=1;
		for(int i=2;i<=n;i++){
			sum=(sum%998244353*i%998244353)%998244353;
		}
		cout<<s;
	}
	return 0;
}
