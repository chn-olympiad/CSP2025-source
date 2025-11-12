#include<bits/stdc++.h>
using namespace std;
int n;
int a[5003];
long long dfs(int i=0,int maxn=0,long long sum=0,int k=0){
	if(i>=n-2&&k==0){
		return 0;
	}
	if(i>=n-1&&k==1){
		return 0;
	}
	if(i==n){
		if(k>=3&&sum>2*maxn){
			return 1;
		}
		else{
			return 0;
		}
	}
	long long q=dfs(i+1,maxn,sum,k)+dfs(i+1,max(maxn,a[i]),sum+a[i],k+1);
	return q%998244353;
}
int J(int k){
	int sum=1;
	for(int i=2;i<=k;i++){
		sum*=i;
	}
	return sum;
}
int C(int n,int m){
	int sum=J(n);
	sum/=J(n-m);
	sum/=J(m);
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	if(a[n-1]==1){
		 int sum=0;
		 for(int i=3;i<=n;i++){
		 	sum+=C(n,i);
		 }
		 cout<<sum%998244353<<endl;
		 return 0;
	}
	cout<<dfs()%998244353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

