#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],p[N],a[N];
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bool f1=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')f1=0;
		if(c[i]==0)f1=0;
	}
	//~ if(f1){
		//~ long long sum=1;
		//~ for(int i=1;i<=n;i++){
			//~ sum=sum*i%mod;
		//~ }
		//~ cout<<sum;
		//~ return 0;
	//~ }
	if(!f1 && m==n){
		cout<<0;
		return 0;
	}
	else if(m==n && f1){
		long long sum=1;
		for(int i=1;i<=n;i++){
			sum=sum*i%mod;
		}
		cout<<sum;
		return 0;
	}
	else if(f1){
		long long sum=1;
		for(int i=1;i<=n;i++){
			sum=sum*i%mod;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)p[i]=i;
	int sum=1;
	for(int i=1;i<=n;i++)sum*=i;
	int res=0;
	for(int i=1;i<=sum;i++){
		int cnt=0,ans=0;
		for(int j=1;j<=n;j++){
			if(cnt>=c[j])cnt++;
			else{
				if(s[i]=='1')ans++;
				else cnt++;
			}
		}
		if(ans>=m)res++;
		next_permutation(p+1,p+n+1);
	}
	cout<<res;
	return 0;
}
