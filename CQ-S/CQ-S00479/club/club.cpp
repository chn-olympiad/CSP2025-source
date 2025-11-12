#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,dp[205][205][205],b[maxn],ans;
struct node{
	int data1,data2,data3;
}a[maxn];
bool vis[maxn];
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i].data2==0&&a[i].data3==0);
		else return 0;
	}
	return 1;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i].data3!=0)return 0;
	}
	return 1;
}
bool cmp(node x,node y){
	return x.data1-x.data2>y.data1-y.data2;
}
bool cmp2(node x,node y){
	return x.data2-x.data1>y.data2-y.data1;
}
void work(){
	int sum=0,cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(b[i]==0)sum+=a[i].data1,cnt1++;
		if(b[i]==1)sum+=a[i].data2,cnt2++;
		if(b[i]==2)sum+=a[i].data3,cnt3++;
	}
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return;
	ans=max(ans,sum);
}
void dfs(int step){
	if(step>n){work();return;}
	for(int i=0;i<=2;i++){
		b[step]=i,dfs(step+1),b[step]=0;
	}
}
bool cmpa(node x,node y){
	return min(x.data1-x.data2,x.data1-x.data3)>min(y.data1-y.data2,y.data1-y.data3);
}
bool cmpb(node x,node y){
	return min(x.data2-x.data1,x.data2-x.data3)>min(y.data2-y.data1,y.data2-y.data3);
}
bool cmpc(node x,node y){
	return min(x.data3-x.data2,x.data3-x.data1)>min(y.data3-y.data2,y.data3-y.data1);
}
int main(){
//	freopen("club4.in","r",stdin);
//	freopen("club.out","w",stdout); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].data1>>a[i].data2>>a[i].data3;
		}
		if(n<10){dfs(1);cout<<ans<<"\n";continue;}
		if(check()){
			sort(a+1,a+n+1,cmp);
//			int ans=0;
			for(int i=1;i<=n/2;i++)ans+=a[i].data1;
			cout<<ans<<"\n";continue;
		}
		if(check2()){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(max(a[i].data1,a[i].data2)==a[i].data1)cnt++;
			}
			if(cnt>=n/2){
				sort(a+1,a+n+1,cmp);
				int sum=0,cnt=0;
				for(int i=1;i<=n;i++){
					if(max(a[i].data1,a[i].data2)==a[i].data1)sum+=a[i].data1,cnt++,vis[i]=1;
					if(cnt==n/2)break;
				}
				for(int i=1;i<=n;i++){
					if(!vis[i])sum+=a[i].data2;
//					else vis[i]=0;
				}
				cout<<sum<<"\n";
			}
			else{
				sort(a+1,a+n+1,cmp2);
				int sum=0,cnt=0;
				for(int i=1;i<=n;i++){
					if(max(a[i].data1,a[i].data2)==a[i].data2)sum+=a[i].data2,cnt++,vis[i]=1;
					if(cnt==n/2)break;
				}
				for(int i=1;i<=n;i++){
					if(!vis[i])sum+=a[i].data1;
//					else vis[i]=0;
				}
				cout<<sum<<"\n";
			}
			for(int i=1;i<=n;i++)vis[i]=0;
			continue;
		}
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int k1=n/2;k1>=0;k1--){
					for(int k2=min(n/2,n-k1);k2>=0;k2--){
						for(int k3=min(n/2,n-k1-k2);k3>=0;k3--){
							int tmp=0;
							if(k1)tmp=max(tmp,dp[k1-1][k2][k3]+a[i].data1);
							if(k2)tmp=max(tmp,dp[k1][k2-1][k3]+a[i].data2);
							if(k3)tmp=max(tmp,dp[k1][k2][k3-1]+a[i].data3);
							dp[k1][k2][k3]=tmp;
						}
					}
				}
			}
			int ans=0;
			for(int k1=0;k1<=n/2;k1++){
				for(int k2=0;k2<=n/2;k2++){
					int k3=n-k1-k2;
					if(k3>n/2)continue;
					ans=max(ans,dp[k1][k2][k3]);
				}
			}
			cout<<ans<<"\n";
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						dp[i][j][k]=0;
					}
				}
			}
			continue;
		}
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			int tmp=max(a[i].data1,max(a[i].data2,a[i].data3));
			if(tmp==a[i].data1)cnt1++;
			if(tmp==a[i].data2)cnt2++;
			if(tmp==a[i].data3)cnt3++;
		}
		if(max(cnt1,max(cnt2,cnt3))==cnt1){
			sort(a+1,a+n+1,cmpa);
			int cnt=0,sum=0;
			for(int i=1;i<=n;i++){
				int tmp=max(a[i].data1,max(a[i].data2,a[i].data3));
				if(tmp==a[i].data1)cnt++,sum+=a[i].data1,vis[i]=1;
//				cout<<a[i].data1<<" "<<a[i].data2<<" "<<a[i].data3<<"\n";
				if(cnt==n/2)break; 
			}
			for(int i=1;i<=n;i++){
				if(!vis[i])sum+=max(a[i].data2,a[i].data3);
			}
			cout<<sum<<"\n";
			for(int i=1;i<=n;i++)vis[i]=0;
			continue;
		}
		if(max(cnt1,max(cnt2,cnt3))==cnt2){
			sort(a+1,a+n+1,cmpb);
			int cnt=0,sum=0;
			for(int i=1;i<=n;i++){
				int tmp=max(a[i].data1,max(a[i].data2,a[i].data3));
				if(tmp==a[i].data2)cnt++,sum+=a[i].data2,vis[i]=1;
				if(cnt==n/2)break; 
			}
			for(int i=1;i<=n;i++){
				if(!vis[i])sum+=max(a[i].data1,a[i].data3);
			}
			cout<<sum<<"\n";
			for(int i=1;i<=n;i++)vis[i]=0;
			continue;
		}
		if(max(cnt1,max(cnt2,cnt3))==cnt3){
			sort(a+1,a+n+1,cmpc);
			int cnt=0,sum=0;
			for(int i=1;i<=n;i++){
				int tmp=max(a[i].data1,max(a[i].data2,a[i].data3));
				if(tmp==a[i].data3)cnt++,sum+=a[i].data3,vis[i]=1;
				if(cnt==n/2)break; 
			}
			for(int i=1;i<=n;i++){
				if(!vis[i])sum+=max(a[i].data1,a[i].data2);
			}
			cout<<sum<<"\n";
			for(int i=1;i<=n;i++)vis[i]=0;
		}
	}
	return 0; 
} 

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


1
2
10 9 8
4 0 0

1
10
4 21 29
6 23 25
3 13 24
5 17 30
14 18 11
8 22 28
12 20 27
15 1 9
2 7 16
26 10 19

1
6
1 0 0
1 0 0
100 100 0
1 0 0
1 0 0
1 0 0



4
4 2 1
3 2 4
5 3 4
3 5 1

1£º1 3
2£º4
3£º2
*/
