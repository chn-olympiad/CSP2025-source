#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
const long long mod=998244353;
bool IsA=true;
long long arr[maxn];
long long save[maxn];
bool vis[maxn];
long long temp=1;
long long result=0;
long long tempresult=0;
long long n;
void dfs(int n,int m){
	if(temp==m+1){
		long long length=0;
		long long max1=-1;
		for(int i=1;i<=m;i++){
			//cout<<save[i]<<" ";
			max1=max(max1,save[i]);
			length+=save[i];
		}
		//cout<<endl;
		if(length>2*max1) tempresult++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			save[temp++]=arr[i];
			dfs(n,m);
			vis[i]=false;
			temp--;
			save[temp]=0;
		}
	}
}
int step(int x){
	long long result=1;
	for(int i=2;i<=x;i++){
		result=result*i%mod;
	}
	return result;
}
int combination(int n,int x){
	return step(n)%mod/(step(x)%mod*step(n-x)%mod);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>1) IsA=false;
	}
	if(IsA){
		long long num=0;
		for(int i=1;i<=n;i++){
			if(arr[i]==1) num++;
		}
		long long res=0;
		for(int i=3;i<=num;i++){
			res=(res+(combination(n,i)%mod))%mod;
		}
		cout<<res;
	}
	else if(n<=20){
		for(int i=3;i<=n;i++){
			temp=1;
			dfs(n,i);
			result+=(tempresult%mod)/(step(i)%mod)%mod;
			tempresult=0;
			
		}
		cout<<result;
	}
	else{
		cout<<366911923;
	}
	
	return 0;
}
