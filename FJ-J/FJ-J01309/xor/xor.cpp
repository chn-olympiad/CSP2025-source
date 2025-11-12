#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,f[500005],s[500005];
int dfs(int x,int y){
	if(f[x]>=y){
		//cout<<f[x]<<" "<<y<<endl; 
		return 0;
	}
	f[x]=y;
	if(x==n+1){
		ans=max(ans,y);
		return 0;
	}
	if(x>n+1){
		return 0;
	}
	for(int i=x;i<=n;i++){
		int m;
		if(i==x){
			m=a[i];
		}
		else{
			m=s[i]^s[x-1];	
		}
		if(m==k){
			dfs(i+1,y+1);
		}
		dfs(i+1,y);
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	memset(f,-1,sizeof(f));
	dfs(1,0);
	cout<<ans;
	return 0;
} 
