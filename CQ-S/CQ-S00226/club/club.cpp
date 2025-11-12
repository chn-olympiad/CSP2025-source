#include <bits/stdc++.h>
using namespace std;
int t;
int n;
const int M=1e5+5;
const int N=5;
int a[M][N];
int Max=INT_MIN;
int ans;
int cnt[N];
int sum[M];
int num[M];
int dp[M][N];
int cnt1[M][N][N];
int vv[M];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x){
	if(x>n){
		Max=max(Max,ans);
		return ;
	}
	int temp=vv[n]-vv[x-1];
	if(ans+temp<Max){
		return ;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			cnt[i]++;
			ans+=a[x][i];
			dfs(x+1);
			cnt[i]--;
			ans-=a[x][i];
	    }
	}
}
struct node {
	int a1,a2;
};
node things[M];
bool cmp2(node x,node y){
	int temp1=abs(x.a1-x.a2);
	int temp2=abs(y.a1-y.a2);
	return temp1>temp2;
}
int main(){
	//1
	//6
//	1 0 0
//2 0 0
//3 0 0
//4  0 0
//5 0 0
//6 0 0
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int _max=INT_MIN;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				_max=max(_max,a[i][j]);
			}
			sum[i]=_max;
		} 
		for(int i=1;i<=n;i++){
			vv[i]=vv[i-1]+sum[i];
		}
		bool flagA=true;
		bool flagB=true;
		bool flagC=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(!a[i][2]==a[i][3]&&a[i][2]==0){
					flagA=false;
					break;
				}
				if(!a[i][3]==0){
					flagB=false;
				}
			}
		}
		if(n<=30){
			Max=INT_MIN;
		    dfs(1);
		    cout<<Max<<"\n";
		} else if(flagA){
			int tt=0;
			for(int i=1;i<=n;i++){
				num[++tt]=a[i][1];
			}
			sort(num+1,num+tt+1,cmp);
			int _ans=0;
			for(int i=1;i<=n/2;i++){
				_ans+=num[i];
			} 
			cout<<_ans<<"\n";
		} else if(flagB){
			for(int i=1;i<=n;i++){
				node temp={a[i][1],a[i][2]};
				things[i]=temp;
			}
			sort(things+1,things+n+1,cmp2);
			int cnt1=0;
			int cnt2=0;
			int _ans=0;
			for(int i=1;i<=n;i++){
				if(things[i].a1>=things[i].a2&&cnt1+1<=n/2){
					cnt1++;
					_ans+=things[i].a1;
				} else if(things[i].a1>=things[i].a2&&cnt1+1>n/2){
					cnt2++;
					_ans+=things[i].a2;
				} else if(things[i].a1<things[i].a2&&cnt2+1<=n/2){
					cnt2++;
					_ans+=things[i].a2;
				}else if(things[i].a1<things[i].a2&&cnt2+1>n/2){
					cnt1++;
					_ans+=things[i].a1;
				}
			} 
			cout<<_ans<<"\n";
		} else {
			memset(dp,-0x3f3f,sizeof dp);
		memset(cnt1,0,sizeof cnt1);
		for(int i=1;i<=3;i++){
			dp[1][i]=a[1][i];
			cnt1[1][i][i]=1;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(cnt1[i-1][k][j]+1<=n/2){
						if(dp[i-1][k]+a[i][j]>dp[i][j]){
						   dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
						   cnt1[i][j][j]=cnt1[i-1][k][j]+1; 
						   for(int kk=1;kk<=3;kk++){
						   	    if(kk==j) continue;
						   	    cnt1[i][j][kk]=cnt1[i-1][k][kk];
						   }	
						}
					}
				}
			} 
		} 
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n"; 
		}
	}
	return 0;
}
