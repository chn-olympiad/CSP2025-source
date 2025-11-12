#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005];
long long dfs(long long x,long long y,long long z,long long sum){
	long long ans=0,k=x+y+z+1;
	if(k>n)return sum;
	if(x>=n/2)
	ans=max(dfs(x,y+1,z,sum+b[k]),dfs(x,y,z+1,sum+c[k]));
	else if(y>=n/2)
	ans=max(dfs(x+1,y,z,sum+a[k]),dfs(x,y,z+1,sum+c[k]));
	else if(k-x-y>n/2)
	ans=max(dfs(x+1,y,z,sum+a[k]),dfs(x,y+1,z,sum+b[k]));
	else ans=max(max(dfs(x+1,y,z,sum+a[k]),dfs(x,y+1,z,sum+b[k])),dfs(x,y,z+1,sum+c[k]));
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool flag1=false,flag2=false;
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i])flag1=true;
			if(c[i])flag2=true;
		}
		if(!flag1&&!flag2){
			sort(a+1,a+1+n);
			int ans=0;
			for(int i=n;i>=n/2+1;i--)
			ans+=a[i];
			cout<<ans<<"\n";
		}
		else
		cout<<dfs(0,0,0,0)<<"\n";
	}
	return 0;
}
