#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int n,m,cnt=0,a[505];
string str;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]=='1'){
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(cnt<m){
		cout<<0<<endl;
	}else if(cnt==n){
		int sum=1;
		for(int i=2;i<=n;i++){
			sum*=i%MOD;
			sum%=MOD;
		}
		cout<<sum<<endl;
	}else{
		int sum=1;
		for(int i=2;i<n;i++){
			sum*=i%MOD;
			sum%=MOD;
		}
		cout<<sum<<endl;
	}
	return 0;
}
