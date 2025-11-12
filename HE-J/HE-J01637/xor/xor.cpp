//t3一般都是二分答案，不知道这题是不是 
//首先，异或前缀和有前缀和的性质，想算出一段区间的异或值就是两个前缀异或和相异或
//求一遍前缀和应该是有用的 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+500;
int sum[N];
int sum0,sum1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int flag=1,flag2=1;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		if(b!=1)flag=0;
		if(b>2)flag2=0;
		if(b==0)sum0++;
		else if(b==1)sum1++;
		sum[i]=sum[i-1];
		sum[i]^=b;//前缀和，求区间l~r的异或和相当于是sum[r]^sum[l-1] 
		//cout<<sum[i]<<" ";
	}
	int ans=0;//统计总个数 
	//感觉有些难，先打个O(n^2)
	if(flag and k==0){//全为1且k为0 
		cout<<n/2;
		return 0;
	}
	if(flag2){
		if(k==1)cout<<sum1;
		else cout<<sum0;
		return 0;
	}
	for(int i=1;i<=n;i++){//都不是那我就开贪 
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
