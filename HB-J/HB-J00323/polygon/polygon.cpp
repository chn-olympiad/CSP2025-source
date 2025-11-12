#include<bits/stdc++.h>
using namespace std;
int n,num[5005],kkksc03,ss,maxn;
bool tf[5005],six=true;
int fkk[10];
long long ans=0,sum;
void dfs2(int now,int how){
	kkksc03=kkksc03*(n-now+1);
	if(now<how)dfs2(now+1,how);
	return;
}
void dfs(int now,int how,int maxn){
	if(now>how){
		if(sum>maxn*2)kkksc03++;
		ans=ans%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(tf[i]){
			tf[i]=false;
			sum+=num[i];
			dfs(now+1,how,max(maxn,num[i]));
			sum-=num[i];
			tf[i]=true;
		}
		if(now==1)tf[i]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> num[i];
		if(num[i]!=1)six=false;
	}
	if(six){
		if(n%2==1){
			for(int i=1;i<=n/2;i++){
				kkksc03=1;
				dfs2(1,i);
				for(int j=2;j<=i;j++)kkksc03=kkksc03/j;
				ans=ans+kkksc03;
				ans=ans%998244353;
			}
			ans*=2;
			ans=ans-n-n*(n-1)/2+1;
			ans=ans%998244353;
			cout << ans;
			return 0;
		}
		else{
			for(int i=1;i<=n/2-1;i++){
				kkksc03=1;
				dfs2(1,i);
				for(int j=2;j<=i;j++)kkksc03=kkksc03/j;
				ans=ans+kkksc03;
				ans=ans%998244353;
			}
			ans*=2;
			kkksc03=1;
			dfs2(1,n/2);
			for(int j=2;j<=n/2;j++)kkksc03=kkksc03/j;
			ans=ans+kkksc03;
			ans=ans%998244353;
			ans=ans-n-n*(n-1)/2+1;
			ans=ans%998244353;
			cout << ans;
			return 0;
		}
	}
	sort(num+1,num+n+1);
	for(int i=3;i<n;i++){
		memset(tf,true,sizeof(tf));
		sum=0;
		dfs(1,i,0);
		for(int j=2;j<i;j++)kkksc03=kkksc03/j;
		ans+=kkksc03;
		kkksc03=0;
		ans=ans%998244353;
	}
	sum=0;
	for(int i=1;i<n;i++)sum+=num[i];
	if(num[n]<sum)ans++;
	ans=ans%998244353;
	cout << ans;
	return 0;
}
