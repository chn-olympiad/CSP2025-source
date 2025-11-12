#include<bits/stdc++.h>
using namespace std;
int t,n,z;
struct sp{
	int i,j,k;
}a[100005];
void dfs(int k,int r1,int r2,int r3,int s){
	if(r1>n/2||r2>n/2||r3>n/2)
		return;
	if(k>n){
		z=max(z,s);
		return;
	}
	dfs(k+1,r1+1,r2,r3,s+a[k].i);
	dfs(k+1,r1,r2+1,r3,s+a[k].j);
	dfs(k+1,r1,r2,r3+1,s+a[k].k);
}
int main(){
  freopen("club3.in","r",stdin);
  freopen("club3.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].i>>a[i].j>>a[i].k;
		dfs(1,0,0,0,0);
		cout<<z<<endl;
		z=0;
	}
	return 0;
}
