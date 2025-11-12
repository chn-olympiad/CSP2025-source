#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n;
int t;
int a[N][4];
int dfs(int k,int sum,int x,int y,int z){
	if(k>n)
		return sum;
	int res=sum;
	for(int i=1;i<=3;i++)
		if((i==1&&x<n/2)||(i==2&&y<n/2)||(i==3&&z<n/2))
			res=max(res,dfs(k+1,sum+a[k][i],x+(i==1),y+(i==2),z+(i==3)));
	return res;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		cout<<dfs(1,0,0,0,0)<<endl;
	}
	return 0;
}
