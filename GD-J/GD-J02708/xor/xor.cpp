#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[(int)(5e5+114)];
int a[(int)(5e5+514)],n,K;

bool kxor(int l,int r){
	int ans=a[r];
	for(int i=l;i<r;i++){
		ans=ans^a[i];
	}
	return ans==K;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf(" %d %d",&n,&K);
	for(int i=1;i<=n;i++) scanf(" %d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++){
			if(kxor(i,j)) dp[j]=max(dp[j],max(dp[i-1]+1,dp[j-1]));
		} 
	}
	printf("%d",dp[n]);
	return 0;
//¶à¸øµã°É qwq 
//   ______
//  |//////|
//  |//Í¼//|
//  |//Áé//|
//  |//////|
// //////////  orz orz orz
// orz orz orz orz orz orz orz orz
// orz orz orz orz orz orz orz orz orz orz
// orz orz orz orz orz orz orz orz orz orz orz orz
// orz orz orz orz orz orz orz orz orz orz orz orz orz orz
// orz orz orz orz orz orz orz orz orz orz orz orz orz orz orz orz
}


