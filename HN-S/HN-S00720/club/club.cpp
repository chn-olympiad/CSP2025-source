#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z;
	int vis;
}a[100006];
int t,n,maxx,k1,k2,k3;
void dfs(int l,int ans){
	if(l==n){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i].vis==0){
			for(int j=1;j<=3;j++){
				a[i].vis=1;
				if(j==1&&k1<n/2){
					k1++;
					dfs(l+1,ans+a[i].x);
					k1--;
				}else if(j==2&&k2<n/2){
					k2++;
					dfs(l+1,ans+a[i].y);
					k2--;
				}else if(k3<n/2){
					k3++;
					dfs(l+1,ans+a[i].z);
					k3--;
				}
				a[i].vis=0;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxx=0,k1=0,k2=0,k3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].vis=0;
		}
		dfs(0,0);
		cout<<maxx<<"\n";
	}
	
	return 0;
}


