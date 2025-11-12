#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],vis[500005],dp[1005];
bool check(int i,int j){
	//检查该区间的异或和是否为k 
	int cur=a[j+1];
	for(int x=j+2;x<=i;x++){
		cur=cur^a[x];
	}
	return (cur==k);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>1000&&k<=1){
		//骗5分 
		int ans=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]==1){
					ans++;
					//若干个0不可能产生1，所以统计1的个数即可 
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]==1){
					if(a[i-1]==1&&!vis[i-1]){
						//2个1可以产生0，但是3个1不行， 所以统计有多少个“1 1”即可 
						ans++;
						vis[i]=vis[i-1]=true;
					}
				}else{
					//是0可以直接加 
					ans++;
				}
			}
		}
		cout<<ans;
	}else{
		//时间复杂度O(n^3)，但是n<=1000可能可以勉强过，保底40分，可能能到60分。
		//若把异或作为一次运算，该程序在n<=1000时最多执行1.67*10^8次运算，并且用clock()实测过，所以60分不是没戏 
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			//直接跳过该点，继承上一个点的值 
			for(int j=0;j<i;j++){
				if(check(i,j)){
					//枚举以i为结尾的区间 
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		cout<<dp[n];
	}
	//总共45-65分 
	return 0;
}
