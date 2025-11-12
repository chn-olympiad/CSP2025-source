#include <bits/stdc++.h>
using namespace std;
int n,m,a[555],bj;
string s;
long long ans;
bool d;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.in","r",stdin);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]==0){
			d=1;
		}
	}
	if(d!=1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}
		cout<<ans;
	}
	else{
		if(m==1){
			for(int i=0;i<n;i++){
				if(s[i]=='1'){
					bj=i;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]>=bj){
					ans++;
				}
			}
			if(ans==0){
				cout<<0;
				return 0;
			}
			else{
				for(int i=1;i<n;i++){
					ans=ans*i%998244353;
				}
			}
			cout<<ans;
		}
		else if(m==n){
			cout<<0;
		}	
	}

	
	
	return 0;
}
