#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<vector<int>>sco(m,vector<int>(n));
	vector<int>nums(m*n);
	for(int i=0;i<m*n;i++){
		cin>>nums[i];
	}
	int R=nums[0];
	sort(nums.begin(),nums.end(),greater<int>());
	if(n>1){
	for(int i=0;i<nums.size();i++){
		sco[i/n][i%m]=nums[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i%2==1){
				sort(sco[i].begin(),sco[i].end());
			}
		}
	}
	int lie,pai;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(sco[i][j]==R){
				lie=i+1;
				pai=j+1+(int)!(n==m);
			}
		}
	}
	cout<<lie<<" "<<pai;
	}
	else{
		sort(nums.begin(),nums.end(),greater<int>());
		for(int i=0;i<nums.size();i++){
			if(nums[i]==R)cout<<1<<" "<<i+1;
		}
	}
	return 0;
}
