#include <bits/stdc++.h>
using namespace std;
int ans=0,n,a[5010];
void f(int sum,int maxn,int k,int t){
	
	if(k==n+1){
		if(t>=3&&sum>2*maxn)ans=(ans+1)%998244353;
		return ;
	}
	f(sum+a[k],max(maxn,a[k]),k+1,t+1);
	f(sum,maxn,k+1,t);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		ans=1;
		for(int k=4,i=4;i<=n;i++){
			ans+=k;
			k=k+k+i-1;
		}
		cout<<ans;
		return 0;
	}
	f(0,0,1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//hope 64
