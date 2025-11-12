#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,js=1,da,ma,bh;
int a[100001][5],tt[5];
void dfs(int x,int y,int ans){
	ans+=a[x][y];
	if(x==n){
		if(ans>da){
			da=ans;
			
		}
		//da[js]=ans;
		js++;
		return ;
	}
	if(y+1<=3&&tt[y+1]+1<=n/2&&a[x][y+1]!=0){
		tt[y+1]+=1;
		tt[y]-=1;
		dfs(x,y+1,ans-a[x][y]);
		tt[y+1]-=1;
		tt[y]+=1;
	}
	for(int i=1;i<=3;i++){
		if(tt[i]+1<=n/2&&a[x+1][i]!=0){
			tt[i]+=1;
			dfs(x+1,i,ans);
			tt[i]-=1;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		tt[1]=1;
		dfs(1,1,0);
		cout<<da<<endl;
		memset(tt,0,sizeof(tt));
		da=0;
	}
	return 0;
} 
