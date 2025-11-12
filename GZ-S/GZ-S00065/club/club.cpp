//GZ-S00065 观山湖区华润中学 刘秦璋 
#include<bits/stdc++.h>
using namespace std;

int n;
int a[100011][4]={};
int ans=0;

void solve(const int &i,const int &s,
	const int &x,const int &y,const int &z){
	if(i==n+1){
		ans=max(ans,s);
		return;
	}
	
	if(x+1<=n/2)
		solve(i+1,s+a[i][1],x+1,y,z);
	if(y+1<=n/2)
		solve(i+1,s+a[i][2],x,y+1,z);
	if(z+1<=n/2)
		solve(i+1,s+a[i][3],x,y,z+1);
	return;
}

void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    	for(int j=1;j<=3;j++)
	    	scanf("%d",&a[i][j]);
	
	ans=0;
	solve(1,0,0,0,0);
	
	printf("%d\n",ans);
	
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	scanf("%d",&_);
	//cin>>_
	while(_--)
		work();
	return 0;
} 
