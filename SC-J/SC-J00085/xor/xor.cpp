#include<bits/stdc++.h>
using namespace std;
int a[500010],dp[500010];
int n,k;
int yihuo(int m,int n){
	int ans=0;
	int i=0;
	while(m>0||n>0){
		if(m%2!=n%2){
			if(i==0)ans+=1;
			else{
				int z=1;
				for(int j=1;j<=i;j++)z*=2;
				ans+=z;
			}
		}
		m/=2;n/=2;i++;
	}
	return ans;
}
int jihe(int l,int r){
	int cnt=0;
	if(l==r&&a[l]==k){
		return 1;
	}
	int t=l,temp=a[t];
	while(t<r){
		temp=yihuo(temp,a[t+1]);		
		t++;
	}
	if(temp==k){
		return 1;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		if(a[n]==k){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	if(k==1){
		int cnt=0,flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
			else if(a[i]!=0){
				flag=1;break;
			}
		}
		if(flag==0){
			cout<<cnt;return 0;
		}
	}
	if(a[1]==k)dp[1]=1;
	else dp[1]=0;
	for(int i=2;i<=n;i++){
		int maxn=0;
		for(int j=1;j<i;j++){
			int temp=dp[j]+jihe(j+1,i);
			if(maxn<temp)maxn=temp;
		}
		dp[i]=maxn;
	}
	cout<<dp[n];
	return 0;
} 