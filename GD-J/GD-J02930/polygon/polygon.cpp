#include<bits/stdc++.h>
using namespace std;
long long a[100000],sum=0;
long long n,k=0;
long long j[100000];
void dfs(int t,int num,long long ma,long long numsum){
	if(num==0){
		if(ma*2<numsum){
			sum++;
		}
		return ;
	}
	for(int i=t;i<=n-1;i++){
		if(j[i]==0){
			j[i]=1;
			dfs(i+1,num-1,max(ma,a[i]),numsum+a[i]);
			j[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}else{
		for(int i=3;i<=n;i++){
			dfs(0,i,-1,0);
		}
	}
	cout<<sum;
	return 0;
}

