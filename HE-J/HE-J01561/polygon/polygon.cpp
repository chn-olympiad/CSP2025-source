#include<bits/stdc++.h>
using namespace std;

long long n,ans;
long long a[5010];
void dfs(long long q,long long p,long long sum,long long maxn,long long &ans){
	if(q>=3&&sum>maxn){
		ans++;
		return ;
	}
	for(long long i=p;i<=n;i++){
		if(maxn>a[i]){
			sum+=a[i];
		}else if(maxn<a[i]){
			sum+=maxn;
			maxn=a[i];
		}
		dfs(q+1,i+1,sum,maxn,ans);
	}
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,1,0,0,ans);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
