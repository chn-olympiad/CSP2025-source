#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long q[N][3],q1[N],q2[N],n,vis[N],max1=-1;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int step,long long sum){
	if(step == n){
		max1 = max(max1,sum);
		return;
	}
	for(int i=0;i<3;i++){
		if(vis[i] < n/2){
			vis[i]++;
			//cout<<sum+q[step][i]<<endl;
			//maxn = max(maxn,sum+q[step][i]);
			//cout<<maxn<<endl;
			dfs(step+1,sum+q[step][i]);
			vis[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n==2){
			long long maxn = -1;
			for(int j=0;j<3;j++)cin>>q1[j];
			for(int j=0;j<3;j++)cin>>q2[j];
			maxn = max(q1[0]+q2[1],q1[0]+q2[2]);
			maxn = max(maxn,q1[1]+q2[2]);
			maxn = max(q1[1]+q2[0],maxn);
			maxn = max(maxn,q1[2]+q2[1]);
			maxn = max(q1[2]+q2[0],maxn);
			cout<<maxn<<endl;
		}
		else{
			int flag=0,v=0;
			for(int j=0;j<n;j++){
				for(int k=0;k<3;k++){
					cin>>q[j][k];
					if(k!=0 && q[j][k]!=0)flag=1;
					if(k!=0 && k!=1 && q[j][k]!=0)v=1;
				}
			}
			if(flag==0 && v==0){
				int a[N];
				long long sum=0;
				for(int j=0;j<n;j++)a[j] = q[j][0];
				sort(a,a+n,cmp);
				for(int j=0;j<n/2;j++)sum+=a[j];
				cout<<sum<<endl;
			}
			else if(n<=10){
				max1=-1;
				dfs(0,0);
				cout<<max1<<endl;
			}
		}
		
	}
	
	return 0;
} 
