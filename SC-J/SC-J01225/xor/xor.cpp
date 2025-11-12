#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10000005];
int dp[10005][10005];
bool A=1;
bool B=1;
bool inside(int l1,int r1,int l2,int r2){
	if(r1>=l2){
		return true;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			A=0;
		}
		if(a[i]!=1&&a[i]!=0){
			B=0;
		}
	}
	if(A){
		if(n%2==0){
			cout<<n/2;
		}else{
			cout<<(n-1)/2;
		}
	}else if(B){
		if(k==1){
			int cnt=0;
			for(int i=0;i<n;i++){
				if(a[i]==1){
					cnt++;	
				}
			}
			cout<<cnt;
		}else{
			int cnt=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					cnt++;
				}
			}
			int tmp=0;
			for(int i=0;i<n;i++){
				if(a[i]==1){
					if(a[i+1]==1){
						i++;
						tmp++;
					}
				}
			}
			cout<<tmp+cnt<<endl;
		}
	}else{
		int ans=0;
		vector<pair<int,int>> rc;
		rc.clear();
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(j==i){
					dp[i][j]=a[i];
				}else{
					dp[i][j]=dp[i][j-1]^a[j];
				}
				if(dp[i][j]==k){
					rc.push_back({i,j});
					ans++;
				}
			}
		}
		int len=rc.size();
		int cnt=1;
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				auto ele1=rc[i];
				auto ele2=rc[j];
				if(!inside(ele1.first,ele1.second,ele2.first,ele2.second)){
					cnt+=1;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}