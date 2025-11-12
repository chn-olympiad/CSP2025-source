#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int t,n;
long long ans=0;
struct node{
	int x,y,z;
}a[N];
void dfs(int ceng,long long sum,int ct1,int ct2,int ct3){
	if(ceng==n+1){
		ans=max(ans,sum);
		return;
	}if(ct1<n/2)dfs(ceng+1,sum+a[ceng].x,ct1+1,ct2,ct3);
	if(ct2<n/2)dfs(ceng+1,sum+a[ceng].y,ct1,ct2+1,ct3);
	if(ct3<n/2)dfs(ceng+1,sum+a[ceng].z,ct1,ct2,ct3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
