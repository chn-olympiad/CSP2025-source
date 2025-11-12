//GZ-S00389 北京师范大学贵阳附属中学 葛森蓥

#include<bits/stdc++.h>
using namespace std;

struct Sit{
	int sum,p[3];
};

int n,l[100001][3],maxx,cur,choosex,choosey;
Sit dp[100001][3];

int ans=-1;
void dfs(int num,int sum,int s1,int s2,int s3){
	if(num==n){
		if(ans<sum){
			ans=sum;
		}
		return;
	}
	if(s1<n/2){
		dfs(num+1,sum+l[num][0],s1+1,s2,s3);
	}
	if(s2<n/2){
		dfs(num+1,sum+l[num][1],s1,s2+1,s3);
	}
	if(s3<n/2){
		dfs(num+1,sum+l[num][2],s1,s2,s3+1);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>l[i][0]>>l[i][1]>>l[i][2];
		}
		ans=0;
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
