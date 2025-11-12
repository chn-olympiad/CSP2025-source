#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int n,k;
int num[10005];
int arr[10005][10005];
int dp[100005];
int cnt=0;
int last=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(k==0 && i==j){
                continue;
            }
            if (num[i]==k){
                dp[i]=1;
                last=i;
                continue;
            }
            int ans=0;
            for(int k=j;k<=i;k++){
                ans=num[k]^ans;
            }
            if(ans==k && num[i]!=0 && j>last){
                dp[i]=max(dp[j]+1,dp[i]);
                last=i;
            }
        }
	}
	int ans=0;
	for(int i=1;i<=n;i++){
        ans+=dp[i];
	}
	printf("%d",ans);
	return 0;
}
