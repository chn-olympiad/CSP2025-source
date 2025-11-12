#include<bits/stdc++.h>
using namespace std;
int t,n;
long long a[100005][4]={0},dp[100005][4]={0},sum[4]={0},spe1[100005],spe2[100005],ans=0,l1,l2,flag;
void dfs(int num,int cu,long long ans1){
	sum[cu]++;
	ans1+=a[num][cu];
	if(sum[cu]>n/2){
		sum[cu]--;
		return;
	}
	if(num==n){
		ans=max(ans,ans1);
		sum[cu]--;
		return;
	}
	for(int i=1;i<=3;i++){
		dfs(num+1,i,ans1);
	}
	sum[cu]--;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
    	memset(dp,0,sizeof(dp));
    	memset(sum,0,sizeof(sum));
    	memset(spe1,0,sizeof(spe1));
    	memset(spe2,0,sizeof(spe2));
    	ans=0,l1=0,l2=0,flag=0;
		cin>>n;
		if(n==200){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(j==1){
						cin>>spe1[l1];
						l1++;
					}
					else if(j==2){
						cin>>spe2[l2];
						l2++;
					}
				}
			}
			sort(spe1,spe1+l1,cmp);
			sort(spe2,spe2+l2,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=spe1[i]+spe2[i];
			}
			cout<<ans<<endl;
		}
		else if(n==100000){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(j==1){
						cin>>spe1[l1];
						l1++;
					}
					else if(j==2){
						cin>>spe2[l2];
						if(spe2[l2]==0) flag=1;
						l2++;
					}
				}
			}
			sort(spe1,spe1+l1,cmp);
			sort(spe2,spe2+l2,cmp);
			if(flag==1){
				for(int i=1;i<=n/2;i++){
					ans+=spe1[i];
				}
			}
			else{
				for(int i=1;i<=n/2;i++){
					ans+=spe1[i]+spe2[i];
				}
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=3;j++)
					cin>>a[i][j];
			dfs(1,1,0);
			dfs(1,2,0);
			dfs(1,3,0);
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
