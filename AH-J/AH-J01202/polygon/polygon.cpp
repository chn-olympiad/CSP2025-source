#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long a[5010],s[5010];
long long n,c,x,y,z;
void dfs(long long i,long long s,long long ma,int t){
	if(t>2&&s>ma*2)c++,c%=998244353;
	for(int j=i+1;j<=n;j++)dfs(j,s+a[j],max(ma,a[j]),t+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
	if(n<=3){
		if(s[3]>max({a[1],a[2],a[3]})*2)cout<<1;
		else cout<<0;
	}else if(s[n]==n){
		for(int i=1;i<=n;i++)x+=i,y+=x,z+=y,z%=998244353;
		cout<<z;
	}else {
		for(long long i=1;i<=n;i++)dfs(i,a[i],a[i],1);
		cout<<c;
	}
	return 0;
}
