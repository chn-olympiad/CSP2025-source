#include <bits/stdc++.h>
using namespace std;
struct f{
	long long int x,y,z;
};
f a[100009],dp[100009];
long long int ans;
int k,n;
bool cmp(f xx,f yy){
	return xx.x>yy.x;
}
void fff(int i,int j,int p){
	ans=max(ans,dp[i].x+dp[j].y);
	if(p>n)return ;
	if(i<n/2){	
		int o=dp[i].x;
		dp[i+1].x=dp[i].x+a[p].x;	
		dp[j+1].y=dp[j].y;
		fff(i+1,j,p+1);
		dp[i].x=o;
	}
	if(j<n/2){
		int o=dp[j].y;
		dp[i+1].x=dp[i].x;	
		dp[j+1].y=dp[j].y+a[p].y;
		fff(i,j+1,p+1);
		dp[i].y=o;
	}
	dp[i+1].x=dp[i].x;	
	dp[j+1].y=dp[j].y;
}
void ff(int i,int j,int l,int p){
	ans=max(ans,dp[i].x+dp[j].y+dp[l].z);
	if(p>n)return ;
	if(i<n/2){	
		int o=dp[i].x;
		dp[i+1].x=dp[i].x+a[p].x;	
		dp[j+1].y=dp[j].y;
		dp[l+1].z=dp[l].z;
		ff(i+1,j,l,p+1);
		dp[i].x=o;
	}
	if(j<n/2){
		int o=dp[j].y;
		dp[i+1].x=dp[i].x;	
		dp[j+1].y=dp[j].y+a[p].y;
		dp[l+1].z=dp[l].z;
		ff(i,j+1,l,p+1);
		dp[i].y=o;
	}
	if(l<n/2){
		int o=dp[l].z;
		dp[i+1].x=dp[i].x;	
		dp[j+1].y=dp[j].y;
		dp[l+1].z=dp[l].z+a[p].z;
		ff(i,j,l+1,p+1);
		dp[i].z=o;
	}
	dp[i+1].x=dp[i].x;	
	dp[j+1].y=dp[j].y;
	dp[l+1].z=dp[l].z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>k;
	while(k--){
		cin>>n;
		ans=0;
		bool o=1,p=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y)o=0;
			if(a[i].z)p=0;
			dp[i].x=dp[i].y=dp[i].z=0;
		}
		if(o&&p){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<endl;
		}
		if(p){
			fff(0,0,1);
			cout<<ans<<endl;
		}
		else {
			ff(0,0,0,1);
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0 
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
