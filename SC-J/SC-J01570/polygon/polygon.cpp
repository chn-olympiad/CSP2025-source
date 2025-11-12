#include<bits/stdc++.h>
using namespace std;
//T4
//警惕精度错误，时间空间错误等，数组不要超过10个，空间不要超过1^7，时间最好不要达到10^8，不用endl，scanf不能读取string和bool
//freopen记得不要注释掉了，不要写fclose，不要关闭流同步
//记得写有返回值的函数写return，main函数只能返回int
//getline不能接在要换行的cin后面，不然会读到换行符。
//考试结束的时候才能登出程序回收系统，不要更换浏览器。
//在代码前面写上一定量的无意义注释
int mod=998244353;
int n,sumn=0;
int arr[5050],vis[5050];
void dfs(int pre){
	int sum=0,mx=0,k=0;
	for(int i=0;i<n;i++){
		if(vis[i]){
			if(arr[i]>mx)mx=arr[i];
			sum+=arr[i];
			k++;
		}
	}
	if(sum>mx*2&&k>=3)sumn++;
	for(int i=pre+1;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i);
			vis[i]=0;
		}
	}
}
unsigned long long jiecheng(int k){
	long long sum=1;
	for(int i=k;i>1;i--)sum*=i;
	return sum;
}
unsigned long long C(int n,int m){
	return (jiecheng(n)/(jiecheng(m)*jiecheng(n-m)))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	unsigned long long mx1=0,sumk=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>mx1)mx1=arr[i];
	}
	if(mx1==1){
		for(int i=3;i<=n;i++){
			sumk+=C(n,i);
			sumk%=mod;
		}
		cout<<sumk%mod;
		return 0;
	}
	dfs(-1);
	cout<<sumn%mod;
	return 0;
}