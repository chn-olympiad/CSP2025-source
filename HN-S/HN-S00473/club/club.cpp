#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],sum1,sum2,sum3,ans[100005];
int dfs(int j){
	if(j>n)return 0;
	int ansj=-1;
	if(sum1<n/2){
		sum1++;
		ansj=max(ansj,a[j][1]+dfs(j+1));
		sum1--;
	}
	if(sum2<n/2){
		sum2++;
		ansj=max(ansj,a[j][2]+dfs(j+1));
		sum2--;
	}
	if(sum3<n/2){
		sum3++;
		ansj=max(ansj,a[j][3]+dfs(j+1));
		sum3--;
	}
	return ansj;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++)cin>>a[j][1]>>a[j][2]>>a[j][3];
		ans[i]=dfs(1);
	}
	for(int i=1;i<=t;i++)cout<<ans[i]<<endl;
	return 0;
}
