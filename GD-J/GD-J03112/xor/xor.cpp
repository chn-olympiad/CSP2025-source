#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k,R[N],dp[N],cnt=1,sum=1;
struct Zb{
	int left,right;
}a[N];
bool cmp(Zb x,Zb y){
	return x.left<y.left || x.left==y.left && x.right<y.right;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>R[i];
		if(i==1) dp[1]=R[1];
		else {
			dp[i]=dp[i-1]^R[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			if((dp[i]^dp[j])==k){
				a[cnt].left=j+1,a[cnt].right=i;
				cnt++;
			}
		}
	}
	sort(a+1,a+cnt,cmp);
	int tmp=a[1].right;
	for(int i=1;i<cnt;i++){
		if(a[i].left>tmp){
			sum++;
			tmp=a[i].right;
		}
	}
	cout<<sum;
	return 0;
}
