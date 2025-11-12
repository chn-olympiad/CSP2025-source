#include<bits/stdc++.h>
using namespace std;
int a[200100],cnt=0,dp[200030],sum[200030],ans=0;
bool f1=1,f2=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
		if(a[i]!=1){
			f1=0;
		}
		if(a[i]!=0&&a[i]!=1){
			f2=0;
		}
		if(a[i]==1){
			cnt++;
		}
	}
	if(f1){
		cout<<n/2;
		return 0;
	}
	if(f2){
		if(k==0){
			cout<<cnt/2;
		}
		else{
			cout<<cnt;
		}
		return 0;
	}
	//以上为25分 O(1)
	//以下是不知道能不能35分的代码 O(n^2)
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			int add=0;
			if((sum[i]^sum[j])==k){//啊啊啊啊又是优先级问题 
				add=1;
			//	cout<<i<<" "<<j<<"\n";
			}
			dp[i]=max(dp[i],dp[j]+add);
		}
	}
	cout<<dp[n];
	//what can I say?
	//10：52 调完以上代码
	//应该有60
	//调完第四题40分就有300了
	//但愿 
}
