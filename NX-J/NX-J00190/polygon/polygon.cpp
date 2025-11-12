#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],Max,ans;
long long n;
void dfs(long long sum,long long step){
	if(step>n){
		Max=0;
		long long pos=n;
		while(b[pos]==0)pos--;
		Max=b[pos];
		if(sum>2*Max){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	b[step]=a[step];
	dfs(sum+a[step],step+1);
	b[step]=0;
	dfs(sum,step+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,1);
	cout<<ans;
	return 0;
}
