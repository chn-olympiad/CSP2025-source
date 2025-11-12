#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,sum,mx,ans,a[5010],b[5010],c[5010],d[5010];
bool f[5010];
void dfs(int x,int s){
	if(x==s+1){
		sum=0;
		mx=0;
		for(int j=1;j<=s;j++){
			sum+=b[j];
			mx=max(mx,b[j]);
		}
		m=0;
		for(int j=1;j<=s;j++){
			c[j]=0;
		}
		for(int j=1;j<=s;j++){
			c[b[j]]++;
		}
		for(int j=1;j<=mx;j++){
			if(c[j]!=d[j]){
				m=1;
				break;
			}
		}
		if((sum>2*mx)&&m){
			ans++;
			for(int j=1;j<=s;j++){
				d[j]=c[j];
			}
		}
		return;
	}
	for(int j=1;j<=s;j++){
		if(f[j]==0){
			f[j]=1;
			b[cnt++]=a[j];
			dfs(x+1,s);
			cnt--;
			f[j]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		m=i;
		dfs(1,i);
	}
	cout<<ans;
	return 0;
}