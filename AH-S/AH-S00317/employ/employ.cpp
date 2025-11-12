#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m;
string s;
int ans;
int a[100005],b[100005],u[100005];
typedef long long ll;
int work(){
	int sum=0,ref=0;;
	for(int i=1;i<=n;i++){
		if(ref>=b[i]){
			ref++;continue;
		}
		if(s[i-1]=='0')ref++;
		else sum++;
	}
	return sum;
}
void dfs(int x){
	if(x==n+1){
		if(work()>=m)ans++;
		ans%=mod;
	}
	for(int i=1;i<=n;i++){
		if(u[i]==0){
			u[i]=1;
			b[x]=a[i];
			dfs(x+1);
			u[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	bool flag=true;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			flag=false;break;
		}
	}
	ll shb;
	if(flag||m==1){
		shb=1;
		for(int i=1;i<=n;i++){
			shb*=i;shb%=mod;
		}
		cout<<shb;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
