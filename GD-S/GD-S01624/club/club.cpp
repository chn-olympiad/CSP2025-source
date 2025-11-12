#include<bits/stdc++.h>
using namespace std;
struct st{
	long long b,c,d;
};
long long t,n,ans=-1e9;
int f[10];
st a[100005];
void dfs(long long x,long long q,long long cnt){
	if(q>n){
		ans=max(ans,cnt);
		return ;
	}
	if(x==1){                         
		dfs(x+1,q,cnt);
		dfs(x+2,q,cnt);
		if(f[1]<n/2){
			f[1]++;
			cnt+=a[q].b;
			dfs(x,q+1,cnt);
			dfs(x+1,q+1,cnt);
			dfs(x+2,q+1,cnt);	
			f[1]--; 	
		}
		
	}
	if(x==2){
		dfs(x+1,q,cnt);
		cnt+=a[q].c;
		if(f[2]<n/2){
			f[2]++;
			dfs(x-1,q+1,cnt);
			dfs(x,q+1,cnt);
			dfs(x+1,q+1,cnt);
			f[2]--;
		}
	}
	if(x==3){
		cnt+=a[q].d;
		if(f[3]<n/2){
			f[3]++;
			dfs(x-2,q+1,cnt);
			dfs(x-1,q+1,cnt);
			dfs(x,q+1,cnt);
			f[3]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int s=1;s<=t;s++){
		cin>>n;
		ans=-1e9;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a[i].b>>a[i].c>>a[i].d; 
		}
		dfs(1,1,0);
		cout<<ans<<endl; 
	}
	return 0;
}

