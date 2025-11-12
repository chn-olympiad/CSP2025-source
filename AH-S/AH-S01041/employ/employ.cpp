#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[1005],used[1005];
long long ans;
string s;//ren     qu     li
void dfs(int k,int all,int lv){
	if(all==m){
		long long sum=1,f=1;
		for(int i=k;i<=n;i++){
			sum=(sum*f)%mod;
			f++;
		}
		ans=(ans+sum)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			used[i]=1;
			if(a[i]<=lv||s[k-1]=='0') dfs(k+1,all,lv+1);
			else dfs(k+1,all+1,lv);
			used[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0,0);
	cout<<ans%mod<<endl;
}
