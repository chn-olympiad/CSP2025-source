#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=998244353;
ll n,m,a[N],b[N],c[N],ans;
string s;
int check(){
	ll cnt=0;
	ll d[N];
	for(int i=0;i<n;i++){
		d[i]=c[i+1];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'&&d[i]>0){
			cnt++;
			cnt%=M;
		}
		if(s[i]=='0'){
			d[i]=0;
			for(int j=i+1;j<n;j++){
				d[j]--;
			}
		}
	}
	return cnt>=m;
}
void dfs(ll l){
	if(l==n){
		if(check()){
			ans++;	
		}
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			c[l+1]=a[i];
			b[i]=1;
			dfs(l+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	m%=M;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;	
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			sum++;
		}
	}
	if(sum==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
		}
		cout<<ans;
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
