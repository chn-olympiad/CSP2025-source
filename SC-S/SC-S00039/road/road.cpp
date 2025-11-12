#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	vector<vector<int> >nums(n+1,vector<int>(n+1,INT_MAX));
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		nums[a][b]=c;
		nums[b][a]=c;
	}
	vector<int>ns(n+1);
	for(int i=0;i<k;i++){
		int s;cin>>s;
		for(int j=1;j<=n;j++)cin>>ns[j];
		for(int j=1;j<=n;j++){
			for(int x=j+1;x<=n;x++){
				nums[j][x]=min(nums[j][x],s+ns[j]+ns[x]);
				nums[x][j]=nums[j][x];
			}
		}
	}
	/*
	for(int i=0;i<nums.size();i++){
	for(int j=0;j<nums.size();j++)cout<<nums[i][j]<<" ";
	cout<<endl;
	}*/
	long long cnt=INT_MAX,ans=0;
	for(int i=1;i<nums.size();i++){
		for(int j=i+1;j<nums.size();j++){
			if(nums[i][j]<cnt)cnt=nums[i][j];
		}
		if(cnt!=INT_MAX)ans+=cnt;
		cnt=INT_MAX;
	}
	cout<<ans;
	return 0;
}
