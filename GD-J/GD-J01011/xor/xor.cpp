#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],dp[500005],len,cnt;
bool flag;
struct r{
	int left,right;
}x[500005];
void count(int tmp){
	for(int i=1;i<=n;i++){
		if(a[i]==tmp){
			cnt++;
		}
	}
}

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
	if(!flag){
		if(k==1){
			count(1);
		}else if(k==0){
			count(0);
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					cnt++;i++;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	//上面是特殊性质A,B 
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(sum[j]^sum[i-1]==k){
				x[++len].left=i;
				x[len].right=j;
			}
		}
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len;j++){
			if(x[j].right>i){continue;}
			dp[i]=max(dp[i],dp[i-x[j].left+1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
