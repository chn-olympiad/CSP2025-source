#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,ans=0,y[5005];
bool visited[5005];
/*void dfs(long long x,long long step){
	for(int i=0;i<n;i++){
		if(a[i]!=x){
			visited[i]=1;
			long long s=0,m=0;
			for(long long j=1;j<=step;j++){
				s+=y[j];
				m=max(m,y[j]);
			}
			if(s>2*m){
				ans++;
			}
			y[step]=&a[i]-a;
			dfs(a[i],step+1);
			y[step]=-1;
			visited[i]=0;
		}
	}
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	memset(y,-1,sizeof(y));
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(n==3){
		if(a[0]+a[1]>a[2]&&a[0]+a[2]>a[1]&&a[2]+a[1]>a[0]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
	/*for(int i=0;i<n;i++){
		//dfs(a[i],1);
		ans%=998244353;
	}*/
	//cout<<ans;
}
