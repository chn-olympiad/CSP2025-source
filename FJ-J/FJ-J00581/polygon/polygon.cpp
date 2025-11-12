#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s[5010],v[5010],cnt;
map<long long,int> mp;
long long hs(int i){
	long long sum=0;
	for(int j=1;j<=i;j++)
		sum=(sum*17+s[i])%998244353;
	return sum;
}
void dfs(int i,int sum,int m){
	if(m*2<sum) cnt++;
	if(i>n) return ;
	for(int j=1;j<=n;j++){
		if(!v[a[j]]){
			s[i]=a[j];
			long long h=hs(i);
			mp[h]++;
			if(mp[h]==1){
				v[a[j]]=1;
				dfs(i+1,sum+a[j],max(m,a[i]));
				v[a[j]]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}
