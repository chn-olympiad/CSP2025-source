#include<bits/stdc++.h> 
using namespace std;
struct node{
	long long x,y,z,id;
}a[100005];
long long s[100005];
long long ans=0;
long long n,t;
void dfs(long long p,long long sum,long long s1,long long s2,long long s3){
	if(p>n){
		ans=max(ans,sum);
		return;
	}
	if(s1!=n/2){
		dfs(p+1,sum+a[p].x,s1+1,s2,s3);
	}
	if(s2!=n/2){
		dfs(p+1,sum+a[p].y,s1,s2+1,s3);
	}
	if(s3!=n/2){
		dfs(p+1,sum+a[p].z,s1,s2,s3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
