//GZ-S00263 遵义市南白中学  杨帆宇 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	vector<int>ans(t);
	cin>>t;
	for(int j = 0;j < t;j++){
	int n;
	cin>>n;
	int dp[n+1];
	for(int p=0;p<n+1;p++){
		dp[p]=0;
	}
	vector<int>des1(1,0);
	vector<int>des2(1,0);
	vector<int>des3(1,0);
	int sum=0;
	int counta=n/2,countb=n/2,countc=n/2;
	for(int i = 1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		int take1;
		if(counta>0){
			take1=dp[i-1]+a;
			des1.push_back(a);
			counta--;
		} 
		if(counta==0){
			sort(des1.begin(),des1.end(),greater<int>());
			take1=dp[i-1]+a-des1[des1.size()-2];//最小的部门1满意度
			des1.pop_back(); 
			des1.pop_back();
			des1.push_back(0);
		}
		//如果取2
		int take2;
		if(countb>0){
			take2=dp[i-1]+b;
			des2.push_back(b);
			countb--;
		} 
		if(countb==0){
			sort(des2.begin(),des2.end(),greater<int>());
			take2=dp[i-1]+b-des2[des2.size()-2];
			des2.pop_back();
			des2.pop_back();
			des2.push_back(0);
		}
		//如果取3;
		int take3;
		if(countc>0){
			take3=dp[i-1]+c;
			des3.push_back(c);
			countc--;
		} 
		if(countc==0){
			sort(des3.begin(),des3.end(),greater<int>());
			take3=dp[i-1]+c-des3[des3.size()-2];
			des3.pop_back();
			des3.pop_back();
			des3.push_back(0);
		}
		dp[i]=max(take1,max(take2,take3));
		sum=max(sum,dp[i]); 
	}
	ans.push_back(sum);
}
	for(int i = 0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}


