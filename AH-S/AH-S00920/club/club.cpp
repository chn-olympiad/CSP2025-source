#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005],c[100005];
long long ma;
long long m[100005];
void dfs(int s,int x,int y,int z,long long ans){
	if(ans+m[n]-m[s-1]<=ma) return;
	if(s==n+1){
		ma=max(ans,ma);
		return;
	}
	if(x+1<=n/2){
		dfs(s+1,x+1,y,z,ans+a[s]);
	}
	if(y+1<=n/2){
		dfs(s+1,x,y+1,z,ans+b[s]);
	}
	if(z+1<=n/2){
		dfs(s+1,x,y,z+1,ans+c[s]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(m,0,sizeof(m));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		bool o2=1,o3=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(b[i]!=0) o2=0;
			if(c[i]!=0) o3=0;
			m[i]=max(a[i],max(b[i],c[i]));
		}
		if(o2&&o3){
			long long sum=0;
			sort(a+1,a+1+n);
			for(int i=n;i>=n/2+1;i--){
				sum+=a[i];
			}
			cout<<sum<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			m[i]+=m[i-1];
		}
		dfs(1,0,0,0,0);
		cout<<ma<<endl;
		ma=0;
	}

	return 0;
}
