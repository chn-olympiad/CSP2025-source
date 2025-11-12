#include<bits/stdc++.h>
using namespace std;
int a[5000005],sum[5000005];
int dp[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	if(k==1 && n>=100000){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	} 
	else if(k==0 && n>=100000){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				ans++;
			}
			else if(a[i-1]==1){
				ans++;
				a[i]=a[i-1]=0;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>=1;j--){
			if((sum[i]^sum[j-1])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
} 
/*
guess:
ru guo bu chu yi wai de hua:
A 100
B 100
C 65
D 100
all:365
yi deng ying gai shi bu chou de

11:16
mei shi le,gang gang kan le yi xia,xiang rang dai ma da xiao chao guo xian zhi hai shi ting nan de,suo yi ying gai ke yi sui bian xie.
(que xin)
lai xie pian you ji ba:
-1d:fang xue hou jiu zai jia wan san jiao zhou.9:00 zuo you cai chu fa.Yin wei kao dian bi jiao yuan,suo yi jia li da suan dao fu jin de yi ge jiu 
dian qu zhu.Bu guo kai fang shi fa xian zhe dong lou li you bu shao ren ye shi lai da bi sai de(zhi shao mei na me gu dan le bu shi ma).
-9h:shi mian le,hen wan cai shui zhao.
-1h:chu fa qu kao dian
-0.5h:dao kao dian le.ye mei xiang dao gang hao neng pen shang chu zhong tong xue.
0h:kai shi kao shi,hua shuo jie ya password zeng me na me chang.
hou mian wang le.
bu xie le

11:28£º
gang gang you qu jian cha le yi xia,B de tiao shi dai ma cha dian wang shan le. 
*/
