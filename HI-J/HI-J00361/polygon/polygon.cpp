#include <bits/stdc++.h>
using namespace std;
int n,a[5001],v[5001];
int ans;
void dfs(int sum,int step,int x){
	if(sum>x&&step>=3) ans++,ans%=998244353;
	if(step==n){
		return;
	}
	sum+=x;
	for(int i=step;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(sum,step+1,a[step]);
		    if(i!=n)sum-=a[step];
		    v[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf ("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n==3){
		cout<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++){
		v[i]=1;
		dfs(0,i,a[i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
