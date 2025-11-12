#include<bits/stdc++.h>
#define thinktwice return
#define code 0
#define once ;
using namespace std;
int n,k,a[114514],book[1145][1145],ans;
bool dp[1145][1145];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a[i]=a[i-1]^x;
	}
	if(k==0){
		int book=1,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=1)book=0;
			if(a[i]==0)sum++;
		}
		cout<<(book?0:sum);
		return 0;
	}
	for(int len=1;len<=n;len++){
		for(int l=1;l<=n-len+1;l+=len){
			int r=l+len-1;
			for(int i=l-1;i<r;i++){
				if(dp[l][i]){
					book[l][r]++;
				}
			}
			if((a[r]^a[l-1]==k&&l==r)||(r-l<=2&&book[l][r]==0&&a[r]^a[l-1]==k)){
				dp[l][r]=1;
			}
			else{
				for(int i=l;i<r;i++){
					if(book[l][i]==0&&a[i]^a[l-1]==k&&a[r]^a[i+1]==k&&book[i+1][r]==0){
						dp[l][r]=1;
						break;
					}
				}
			}
		}
	}
	cout<<book[1][n];
	thinktwice code once
}
