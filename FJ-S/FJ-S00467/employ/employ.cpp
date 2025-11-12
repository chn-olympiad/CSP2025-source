#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,ans=1;
string s;
int a[505];
bool flag=false;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') k++;
	}
	if(k<m){
		cout<<0;
		return 0;
	}
	else if(n==m){
		cout<<0;
		return 0;		
	}
	else if(n==1){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=m;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}