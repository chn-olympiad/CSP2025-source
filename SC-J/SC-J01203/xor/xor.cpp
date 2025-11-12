#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;
int dp[15][15];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		a.push_back(t);
	}
	int maxx=0,tmp,bj;
	if(k==0) cout<<1;
	else{
		for(int i=0;i<a.size();i++){
			for(int j=i+1;j<a.size();j++){
				dp[i][j]=int(dp[i][j-1]^a[i+j]);
				if(dp[i][j]==k){
					if(tmp>i){
						continue;
						bj++;	
					}
					else{
						tmp=0,maxx+=bj-1;
					}
					if(j==1) maxx++;
					else{
						tmp=i+j;
					}	
				}
			}
		}
	}
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			dp[i][j]=int(dp[i][j-1]^a[i+j]);
			if(dp[i][j]==k){
				if(tmp>i){
					continue;
					bj++;	
				}
				else{
					tmp=0,maxx+=bj-1;
				}
				if(j==1) maxx++;
				else{
					tmp=i+j;
				}	
			}
		}
	}
	cout<<maxx;
	return 0;
}
/*
4 3
2 1 0 3

*/
