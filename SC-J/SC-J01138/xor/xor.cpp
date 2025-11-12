#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500010];
long long sum[500010];//前缀异或和, sum[i]^sum[i-m-1]表示i到m的区间异或和 
int ans[500010];//统计截止到i的最佳答案 
bool flag=0;
bool book[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]>1){
			flag=1;
		}
	}
	if(flag==0){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
		}else{
			int cnt1=0;
			int cnt2=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt1++;
				}else{
					if(a[i+1]==1&&book[i]==0){
						cnt2++;
						book[i+1]=1;
					}
				}
			}
			cout<<cnt1+cnt2;
		}
	}else{
		for(int i=1;i<=n;i++){
			ans[i]=ans[i-1];
			for(int j=i;j>=1;j--){
				if((sum[i]^sum[j-1])==k){
					ans[i]=max(ans[i],ans[j-1]+1);
				}
			}
		}
		cout<<ans[n];
	}
	return 0;
}