#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;
int n,ml,j,ans,mod=998244353,sum;
int a[5010];
bool b[5010];
bool cmp(int a,int b){
	return a<b;
}
void dfs(int x,int z){
	if(x==0){
		if(ans>ml){
			sum=(sum+1)%mod;  
		}
		return ;  
	}
	for(int k=z; k<j; k++){
		if(b[k]==1){ 
			b[k]=0;
			ans+=a[k]; 
			dfs(x-1,k+1);
			ans-=a[k];
			b[k]=1;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool f=1;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) f=0;
		b[i]=1;
	}
	if(f){
		cout<<0;
		return 0;
	}
	for(int i=3; i<=n; i++){
		for(j=i; j<=n; j++){
			ml=a[j]*2;
			ans=a[j];  
			dfs(i-1,1);
		}
	}
	cout<<sum;
	return 0;
}
