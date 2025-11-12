#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010][10];
int b[100010];
int dp[4][100010];
int ans=0;
void dfs(int pos,int cnt1,int cnt2,int cnt3,int sum,int x){
	if((cnt1>(n/2))||(cnt2>(n/2))||(cnt3>(n/2))) return ;
//	cout<<"pos="<<pos<<" i="<<x<<" sum="<<sum<<endl;
	if(pos==n+1){
		ans=max(sum,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			dfs(pos+1,cnt1+1,cnt2,cnt3,sum+a[pos][i],i);
		}else if(i==2){
			dfs(pos+1,cnt1,cnt2+1,cnt3,sum+a[pos][i],i);		
		}else{
			dfs(pos+1,cnt1,cnt2,cnt3+1,sum+a[pos][i],i);		
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int flag=1;
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]!=0||a[i][3]!=0){
				flag=0;
				break;
			}
		}
		if(flag==0&&n<=10){
			dfs(1,0,0,0,0,0);
		}else{
			for(int i=1;i<=n;i++){
				b[i]=a[i][2];
			} 
			sort(b+1,b+1+n);
			for(int i=n;i>=n/2+1;i--){
				ans+=b[i];
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	
	
	return 0;
} 
