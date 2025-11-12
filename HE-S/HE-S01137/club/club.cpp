#include<bits/stdc++.h>
using namespace std;
int n,maxx,maxs,vis[100005],a[100005][5],b[5],sum;
void dfs(int ms,int x){
	if(b[1]>maxx||b[2]>maxx||b[3]>maxx){
		return ;
	}
	if(ms==0){
		if(sum>=maxs){
			maxs=sum;
		}
		return ;
	}
	for(int j=1;j<=3;j++){
		sum+=a[x][j];
		b[j]++;
		dfs(ms-1,x+1);
		b[j]--;
		sum-=a[x][j];
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		maxx=n/2;
		maxs=0;
		sum=0;
		dfs(n,1);
		cout<<maxs<<endl;
	}
	return 0;
} 
