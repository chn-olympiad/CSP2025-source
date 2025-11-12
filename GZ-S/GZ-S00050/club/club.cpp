// GZ-S00050 遵义市第一中学 刘子晨 
#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t;
int n;
int a[MAXN][10];
//struct node{
//	int fir,sec,thi;	
//}a[MAXN];
int dp[MAXN];
int vis[10];
//void quicksort(int l,int r,int a[]){
//	if(l>=r)return;
//	int o_l=l,o_r=r;
//	int key=a[l];
//	while(l!=r){
//		while(l<r&&a[r]>=key)r--;
//		a[l]=a[r];
//		while(l<r&&a[l]<=key)l++;
//		a[r]=a[l];
//	}
//	a[l]=key;
//	quicksort(o_l,l-1,a);
//	quicksort(l+1,o_r,a);
//}
int maxn=0;
int temp;
int mn[MAXN];
void dfs(int step,int sum){
	if(step==n+1){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		sum+=a[step][i];
		vis[i]++;
		if(vis[i]<=temp){
			dfs(step+1,sum);
			
		}
		sum-=a[step][i];
		vis[i]--;
		
	}
}
void dfs2(int step,int sum){
	if(step==n+1){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=2;i++){
		sum+=a[step][i];
		vis[i]++;
		if(vis[i]<=temp){
			dfs(step+1,sum);
			
		}
		sum-=a[step][i];
		vis[i]--;
		
	}
}
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxn=0;
		cin>>n;
		temp=n/2;
		vis[1]=0;vis[2]=0;vis[3]=0;
		int max=0;
		int s1=0,s2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			mn[i]= a[i][1];
			if(a[i][2]==0&&a[i][3]==0){//A
				s1++;
			}
			if(a[i][3]==0){//B
				s2++;
			}
		}
	//	cout<<s1<<endl;
		if(s1==n){
			sort(mn+1,mn+n+1,cmp);
			int summ=0;
			for(int i=1;i<=n/2;i++){
				summ+=mn[i];
			}
			cout<<summ<<endl;
		} 
//		else if(s2==n){
//			dfs2(0,0);
//			cout<<maxn<<endl;
//			cout<<"WWWWW"<<endl;
//		}
		else{
			dfs(0,0);
			cout<<maxn<<endl;
		}	
		
	}
	
	fclose(stdin);
	fclose(stdout);
}

