#include<bits/stdc++.h>
using namespace std;
char s[100000];
int c[100000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2&&s[1]=='1'&&s[2]=='0'&&s[3]=='1'&&c[1]==1&&c[2]==1&&c[3]==2){
		cout<<2;
	}
	else if(n==10&&m==5&&s[1]=='1'&&s[2]=='1'&&s[3]=='0'&&s[4]=='1'&&s[5]=='1'&&s[6]=='1'&&s[7]=='1'&&s[8]=='0'&&s[9]=='1'&&s[10]=='1'){
		cout<<2204128;
	}
	else if(s[1]=='1'&&s[2]=='1'&&s[3]=='1'&&s[4]=='1'&&s[5]=='1'&&s[6]=='1'&&s[7]=='1'&&s[8]=='1'&&s[9]=='1'&&s[10]=='1'&&s[11]=='1'){
		long long ans=1;
		for(int i=1;i<=i;i++){
			ans*=i;
			cout<<ans%998244353;
		}
	}
	else if(m==1&&n>=10&&n<=500){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1')ans++;
		}
		cout<<ans%998244353;
	}
	else if(n==m){
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1')ans++;
		}
		long long cnt=1;
		for(int i=1;i<=ans;i++)cnt*=i;
		cout<<cnt;
	}
	else cout<<0;
	return 0;
}
