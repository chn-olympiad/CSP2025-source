#include<bits/stdc++.h>
using namespace std;
long long t,n,a[1000000],b[1000000],c[1000000],ans;
struct node{
	long long x,y,z;
}d[1000000];
bool f1,f2;
void dfs(long long sum1,long long sum2,long long sum3,long long u,long long cnt){
	if(u>n){
		ans=max(cnt,ans);
		return;
	}
	if(sum1<n/2){
		dfs(sum1+1,sum2,sum3,u+1,cnt+d[u].x);
	}
	if(sum2<n/2){
		dfs(sum1,sum2+1,sum3,u+1,cnt+d[u].y);
	} 
	if(sum3<n/2){
		dfs(sum1,sum2,sum3+1,u+1,cnt+d[u].z);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		f1=1,ans=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			d[i].x=a[i],d[i].y=b[i],d[i].z=c[i];
			if(c[i]>0||b[i]>0){
				f1=0;
			}
		}
		if(f1){
			sort(a,a+1+n);
			for(long long i=n;i>n/2;i--){
				ans+=a[i];
			}
		}
		if(n<=200){
			dfs(0,0,0,1,0);
		}
		else{
			for(long long i=1;i<=n;i++){
				ans+=max(d[i].x,max(d[i].y,d[i].z));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

