#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,m,a[505],cnt=0;
string s;
long long ans;
long long jiecheng(int w){
	long long ans=1;
	for(int i=2;i<=w;i++){
		ans=ans*i%MOD;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt++;
	}
	if(n==m){
		bool f=1;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				f=0;break;
			}
		}
		if(f&&cnt==0) ans=jiecheng(n);
		else ans=0;
	}else if(n==1){
		int q=-1;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				q=i+1;break;
			}
		}
		ans=0;
		if(q>0){
			for(int i=1;i<=n;i++){
				if(a[i]>=q) ans++;
			}
		}
		ans=ans*jiecheng(n-1)%MOD;
	}else{
		ans=jiecheng(n-cnt);
	}
	cout<<ans;
	return 0;
}
