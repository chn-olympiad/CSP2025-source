#include <bits/stdc++.h>
using namespace std;
long long n,t,a[1000005],b[1000005],c[1000005],maxs;
void dfs(long long i,long long cnt1,long long cnt2,long long cnt3,long long sum){
	if(cnt1>n/2 || cnt2>n/2 || cnt3>n/2){
		return;
	}
	if(i==n+1){
		maxs=max(maxs,sum);
		return;
	}
	dfs(i+1,cnt1+1,cnt2,cnt3,sum+a[i]);
	dfs(i+1,cnt1,cnt2+1,cnt3,sum+b[i]);
	dfs(i+1,cnt1,cnt2,cnt3+1,sum+c[i]);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxs=0;
		cin>>n;
		bool f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 || c[i]!=0){
				f=1;
			}
		}
		if(!f){
			sort(a+1,a+1+n,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i];
			}
			cout<<sum<<"\n";
			continue;
		} 
		dfs(1,0,0,0,0);
		cout<<maxs<<"\n";
	}
	return 0;
}
