#include<bits/stdc++.h>
using namespace std;
int a[10005][15],f[10005],l[10005];
int t,x=0,y=0,z=0,e;int n;
int dfs(int h){
	if(h>n){
		return 0;
	}
	if(x<n/2&&y<n/2&&z<n/2){
		f[h]=f[h+1]+max(max(a[h][1],a[h][2]),a[h][3]);
		 e=max(max(a[h][1],a[h][2]),a[h][3]);
		if(e==a[h][1]){
			x++;
		}
		else if(e==a[h][2]){
			y++;
		}
		else{
			z++;
		}
	}
	else if(x<n/2&&y<n/2&&z>=n/2){
			f[h]=f[h+1]+max(a[h][1],a[h][2]);
			e=max(a[h][1],a[h][2]);
		if(e==a[h][1]){
			x++;
		}
		else {
			y++;
		}
	}
	else if(x<n/2&&z<n/2&&y>=n/2){
			f[h]=f[h+1]+max(a[h][1],a[h][3]);
			e=max(a[h][1],a[h][3]);
		if(e==a[h][1]){
			x++;
		}
		else {
			z++;
		}
	}
	else if(z<n/2&&y<n/2&&x>=n/2){
			f[h]=f[h+1]+max(a[h][3],a[h][2]);
			e=max(a[h][3],a[h][2]);
		if(e==a[h][3]){
			z++;
		}
		else {
			y++;
		}
	}
	h++;
	dfs(h);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;f[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3]; 
		}
		dfs(1);x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			f[i]=f[i]+f[i-1];
		}
		
		cout<<f[n];
		}
} 
