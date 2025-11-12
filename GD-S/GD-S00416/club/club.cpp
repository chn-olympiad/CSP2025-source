#include<bits/stdc++.h>
using namespace std;
int n,maxn=-1;
int f[100010][4]={},arr[100010]={};
void dfs(int cnt,int p,int l,int m,int r){
	if(p>n+1)
		return;
	maxn=max(cnt,maxn);
//	cout<<maxn<<" "<<cnt<<" "<<p<<endl;
	if(l<n/2)
		dfs(cnt+f[p][1],p+1,l+1,m,r);
	if(m<n/2)
		dfs(cnt+f[p][2],p+1,l,m+1,r);
	if(r<n/2)
		dfs(cnt+f[p][3],p+1,l,m,r+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					scanf("%d",&f[i][j]);
				}
			}
			dfs(0,1,0,0,0);
			cout<<maxn<<endl;
			maxn=0;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					scanf("%d",&f[i][j]);
				}
				arr[i]=f[i][1];
			}
			sort(arr+1,arr+n+1);
			for(int i=n;i>=n/2;i--){
				maxn+=arr[i];
			}
			cout<<maxn<<endl;
			maxn=0; 
		}
	}
	return 0;
}
