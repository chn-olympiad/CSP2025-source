#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=550,M=998244353;
int n,m,c[N],ans,cj[N];
char s[N];
bool f[N];
void dfs(int p,int sum){
	if(p>n){
		if(sum>=m){
			ans=(ans+1)%M;
			return;
		}
		else{
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		if(cj[p]>=c[i]||s[p]=='0'||p-sum-1>=c[i]){
			dfs(p+1,sum);
		}
		else{
			dfs(p+1,sum+1); 
		}
		f[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cj[i]=cj[i-1];
		if(s[i]=='0'){
			cj[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans%M;
	return 0;
}
