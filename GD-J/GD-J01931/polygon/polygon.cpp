#include<bits/stdc++.h>
using namespace std;
int mod=998244353; 
int n,a[5001],maxx,k;
long long cnt;
bool f[5001];
void dfs(int sum,int pos){
	if(sum>2*maxx){
		if(pos>=3){
			cnt++;
			cnt%=mod;
		}
		return;
	}
	if(pos==n+1){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			//选 
			f[i]=true;
			k=maxx;
			maxx=max(a[i],maxx); 
			dfs(sum+a[i],pos+1);
			//不选 
			f[i]=false;
			maxx=k;
			dfs(sum,pos);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a[1]>>a[2]>>a[3];
		maxx=max({a[1],a[2],a[3]});
		if(a[1]+a[2]+a[3]>maxx*2){
			cout<<1;
		}
		else cout<<0;
	}
	else if(n<=6){
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		//三角形 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>a[k]*2) cnt++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			//四边形 
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int s=k+1;s<=n;s++){
						if(a[i]+a[j]+a[k]+a[s]>a[s]*2) cnt++;
					} 
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*max({a[1],a[2],a[3],a[4],a[5],a[6]})) cnt++;
		cout<<cnt;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(0,0);
		cout<<cnt;
	}
	return 0;
}
