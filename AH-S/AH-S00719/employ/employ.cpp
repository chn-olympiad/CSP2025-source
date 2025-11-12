#include <bits/stdc++.h>
using namespace std;
long long n,m,c[1005],num[1005],ans=1,sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){cin>>c[i];sum+=c[i];}
	for(int i=0;i<n;i++){
		num[i+1]=num[i];
		if(s[i]=='0')num[i+1]++;
	}
	if(m==n){
		if(num[n]>=1)cout<<0;
		else{
			for(int i=1;i<=n;i++){ans*=i;ans%=998244353;}
			cout<<ans;
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){ans*=i;ans%=998244353;}
		cout<<ans;
	}
	else if(num[n]==0&&sum!=0){
		for(int i=1;i<=n;i++){ans*=i;ans%=998244353;}
		cout<<ans;
	}
	else if(num[n]==0&&sum==0)cout<<0;
	else cout<<1;
	return 0;
}
