#include<bits/stdc++.h>
using namespace std;
int a[1000053][3];
long long cnt=0,n=0;
void dfs(int x,int y,int z,int p,int mr,long long ans){
	if(x>mr)return ;
	if(y>mr)return ;
	if(z>mr)return ;
	if(x+y+z==n)cnt=max(cnt,ans);
	dfs(x+1,y,z,p+1,mr,ans+a[p][0]); 
	dfs(x,y+1,z,p+1,mr,ans+a[p][1]); 
	dfs(x,y,z+1,p+1,mr,ans+a[p][2]); 
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0); 
	int t;
	cin>>t;
	while(t--){
		int mr=0;
		cin>>n;
		mr=n/2;
//		for(int i=0;i<=n+1;i++)a[i].x=0,a[i].y=0,a[i].z=0;
//		for(int i=0;i<=n+1;i++)ax[i].x=0,ax[i].y=0,ax[i].z=0;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		cnt=0;
		dfs(0,0,0,1,mr,0);
		cout<<cnt<<"\n";
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
struct st{
	int a,b;
};
struct ed{
	int x,y,z;
};
int a[1000053][3];
bool cmp(st x,st y){
	return x.a>y.a;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0); 
	int t;
	cin>>t;
	while(t--){
		int n=0,mra=0,mrb=0,mrc=0,mr=0,mrz=0;
		long long cnt=0;
		cin>>n;
		mr=n/2;
//		for(int i=0;i<=n+1;i++)a[i].x=0,a[i].y=0,a[i].z=0;
//		for(int i=0;i<=n+1;i++)ax[i].x=0,ax[i].y=0,ax[i].z=0;
		vector<st> v1;
		vector<st> v2;
		vector<st> v3;
		v1.clear();
		v2.clear();
		v3.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				v1.push_back({a[i].x,i});
				if(a[i].y>a[i].z){
					ax[i][0]=1;
					ax[i][1]=2;
					ax[i][2]=3;
				}else{
					ax[i][0]=1;
					ax[i][1]=3;
					ax[i][2]=2;
				}
			}else if(a[i].y>a[i].x&&a[i].y>a[i].z){
				v2.push_back({a[i].y,i});
				if(a[i].x>a[i].z){
					ax[i][0]=2;
					ax[i][1]=1;
					ax[i][2]=3;
				}else{
					ax[i][0]=2;
					ax[i][1]=3;
					ax[i][2]=1;
				}
			}else{
				v3.push_back({a[i].z,i});
				if(a[i].x>a[i].y){
					ax[i][0]=3;
					ax[i][1]=1;
					ax[i][2]=2;
				}else{
					ax[i][0]=3;
					ax[i][1]=2;
					ax[i][2]=1;
				}
			}
		}
		sort(v1.begin(),v1.end(),cmp);
		for(st e:v1){
			cout<<e.a<<" ";
			if(mra<mr){
				cnt+=e.a;
			}else{
				if(ax[e.b][1]==1){
					v2.push_back({a[e.b].x,e.b});
				}else if(ax[e.b][1]==2){
					v2.push_back({a[e.b].y,e.b});
				}else{
					v2.push_back({a[e.b].z,e.b});
				}
				
			}
			mra+=1;
			mrz+=1;
			if(mrz>=n)break;
		}
		cout<<"\n";
		sort(v2.begin(),v2.end(),cmp);
		for(st e:v2){
			cout<<e.a<<" ";
			if(mrz>=n)break;
			if(mrb<mr){
				cnt+=e.a;
			}else{
				if(ax[e.b][1]==1){
					v3.push_back({a[e.b].x,e.b});
				}else if(ax[e.b][1]==2){
					v3.push_back({a[e.b].y,e.b});
				}else{
					v3.push_back({a[e.b].z,e.b});
				}
			}
			mrb+=1;
			mrz+=1;
			if(mrz>=n)break;
		}
		cout<<"\n";
		sort(v3.begin(),v3.end(),cmp);
		for(st e:v3){
			cout<<e.a<<" ";
			if(mrz>=n)break;
			if(mrc<mr){
				cnt+=e.a;
			}else{
				break;
			}
			mrc+=1;
			mrz+=1;
			if(mrz>=n)break;
		}
		cout<<"               "<<cnt<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct st{
	int a,b;
};
struct ed{
	int x,y,z;
};
int a[1000053][3];
long long dp[253][253][253];
bool cmp(st x,st y){
	return x.a>y.a;
}
int main(){
	freopen("club2.in","r",stdin);
	freopen("club2.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0); 
	int t;
	cin>>t;
	while(t--){
		int n=0,mra=0,mrb=0,mrc=0,mr=0,mrz=0;
		long long cnt=0;
		cin>>n;
		mr=n/2;
//		for(int i=0;i<=n+1;i++)a[i].x=0,a[i].y=0,a[i].z=0;
//		for(int i=0;i<=n+1;i++)ax[i].x=0,ax[i].y=0,ax[i].z=0;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)dp[i][j][k]=0;
		for(int i=1;i<=n;i++){
			for(int x=0;x*2<=n&&x<=i;x++){
				for(int y=0;(x+y<=i&&(y*2<=n));y++){
					if(x-1>=0)dp[x][y][i-x-y]=max(dp[x][y][i-x-y],dp[x-1][y][i-x-y]+a[i][0]);
					if(y-1>=0)dp[x][y][i-x-y]=max(dp[x][y][i-x-y],dp[x][y-1][i-x-y]+a[i][1]);
					if(i-x-y>=0)dp[x][y][i-x-y]=max(dp[x][y][i-x-y],dp[x][y][i-x-y-1]+a[i][2]);
//					if(i-x-y<=mr)cnt=max(cnt,dp[x][y][i-x-y]);
					cnt=max(cnt,dp[x][y][i-x-y]);
//					cout<<x<<" "<<y<<" "<<i-x-y<<" "<<dp[x][y][i-x-y]<<"\n";
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
*/
