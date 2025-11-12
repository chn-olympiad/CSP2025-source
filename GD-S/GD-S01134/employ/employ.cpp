#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353; 
long long n,m,a[505],b[505],ans,x,sss,ss[505];
string s;
bool v[505],f;
void dfs(long long k){
	if(k==n+1){
		long long giveup=0,as=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||a[b[i]]<=giveup)giveup++;
			else if(s[i-1]=='1'&&a[b[i]]>giveup)as++;
		}
		if(as>=m)ans++;
		ans=ans%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			b[k]=i;
			dfs(k+1);
			v[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)x++;
		if(s[i-1]=='0')f=1;
		if(s[i-1]=='1')sss++;
		ss[a[i]]++;
	}
	cout<<x<<endl;
	if(n-x<m||sss<m){
		cout<<0;
		return 0;
	}
	if(!f){
		if(x==0){
			long long ssss=1;
			for(int i=1;i<=n;i++)ssss=(ssss%MOD)*(i%MOD)%MOD;
			cout<<ssss%MOD;
			return 0;
		}
	}
	if(m==1){
		if(x==0){
			long long ssss=1;
			for(int i=1;i<=n;i++)ssss=(ssss%MOD)*(i%MOD)%MOD;
			cout<<ssss%MOD;
			return 0;
		}
	}
	dfs(1);
	cout<<ans%MOD;
	return 0;
}

