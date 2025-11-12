#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5;
int dt[maxn][4];
int n,t,ans,flag;

void dfs(int x,int y,int sum,int a1,int b1,int c1){
	if(x==n){
		ans=max(sum,ans);
		return;
	}
	if(a1>=1){
		dfs(x+1,1,sum+dt[x+1][1],a1-1,b1,c1);
	}
	if(b1>=1){
		dfs(x+1,2,sum+dt[x+1][2],a1,b1-1,c1);
	}
	if(c1>=1){
		dfs(x+1,3,sum+dt[x+1][3],a1,b1,c1-1);
	}
}

int cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		flag=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>dt[i][j];
				if((j==2||j==3)&&dt[i][j]!=0)flag=0;
			}
		}
		if(flag==1){
			int s[maxn];
			for(int i=1;i<=n;i++){
				s[i]=dt[i][1];
			}
			sort(s+1,s+n+1,cmp);
			int ans1=0;
			for(int i=1;i<=n/2;i++){
				ans1+=s[i];
			}
			cout<<ans1;
		}
		else{
			ans=0;
			dfs(0,0,0,n/2,n/2,n/2);
			cout<<ans<<endl;
		}
	}
	return 0;
}



