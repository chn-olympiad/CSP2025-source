#include<bits/stdc++.h>
using namespace std;

/*
题目要求：
- 在所有数中取出n组
- 使得每一组的异或值均为k
- 并使得n最大

双指针（贪心）+前缀异或优化
时间复杂度：O(n*n)
n<=5e5(部分成立（60分）)
*/

const int MAXN=5e5+10;
int n,k;
int sum[MAXN];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		//前缀"和"预处理
		sum[i]=(sum[i-1]^sum[i]);
	}
	
	int l=0,r=1,ans=0;
	while(r<=n){
		bool flag=false;
		for(int i=r;i<=n;i++){
			for(int j=l;j<i;j++){
				if((sum[i]^sum[j])==k){
					l=i,r=i+1,ans++;
					flag=true;
					break;
				}
			}
			if(flag) break;
			if(i==n) r=n+1;
		}
	}
	cout<<ans;
	return 0;
}