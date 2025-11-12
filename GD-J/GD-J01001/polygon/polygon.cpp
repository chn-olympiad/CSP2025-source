#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n;
int a[505];
int power(int k){
	int cnt=1;
	while(k){
		cnt*=2;
		cnt%=998244353;
		k--;
	}
	return cnt;
}
void dfs(int cnt,int Max,int now){
	if(cnt>a[Max+1]){
		ans+=power(Max-now);
		ans%=998244353;
		return;
	}
	for(int i=now+1;i<=Max;i++){
		dfs(cnt+a[i],Max,i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	if(a[n]==1){
		cout<<(power(n)-n+998244353)%998244353;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(0,i-1,0);
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
