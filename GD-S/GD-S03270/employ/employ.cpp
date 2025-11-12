#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
long long n,m,a[510],z[510],q[510],dp[510][510][510],sum;
long long Mod=998244353;
string s;
bool r=true,f[510];
void dfs(int r,int p){
	if(r==n&&p>=m){
		sum++;
		return;
	}
	for(int i=1;i<=z[r];i++){
		if(!f[i]){
		    f[i]=true;
		    dfs(i,p+1);
		    f[i]=false;
		}
	}
	for(int i=z[r]+1;i<=n;i++){
		if(!f[i]){
		    f[i]=true;
		    dfs(i,p);
		    f[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]=='0'){
		    q[i]=q[i-1]+1;
		    r=false;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z[i]=lower_bound(q+1,q+n+1,a[i])-q;
	}
	sort(z+1,z+n+1);
	if(r){
		sum=1;
		for(int i=2;i<=n;i++){
			sum*=i;
			sum%=Mod;
		}
		cout<<sum;
		return 0;
	}
	f[1]=true;
	dfs(1,0);
	cout<<sum;
	return 0;
}
