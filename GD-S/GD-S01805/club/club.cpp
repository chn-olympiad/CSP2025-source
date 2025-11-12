#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
//const int INF=0x3f3f3f3f3f;
int T;
int n;
int maxx=0;
int a[N][3];
void dfs(int k,int sum,int x,int y,int z){
	if(x>n/2)return ;
	if(y>n/2)return ;
	if(z>n/2)return ;
	if(k==n+1){
		maxx=max(maxx,sum);
		return;
	}
	dfs(k+1,sum+a[k+1][1],x+1,y,z);
	dfs(k+1,sum+a[k+1][2],x,y+1,z);
	dfs(k+1,sum+a[k+1][3],x,y,1+z);
	
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int
		maxx=0;int maxc=0,maxb=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==3)maxc=max(maxc,a[i][j]);
				if(j==2)maxb=max(maxb,a[i][j]);
			}
		}
		if(n<=10)dfs(0,0,0,0,0);
		if(maxc==0&&maxb==0){
			vector<int>v;
			for(int i=1;i<=n;i++)v.push_back(a[i][1]);
			sort(v.begin(),v.end(),cmp);
			for(int i=0;i<n/2;i++)maxx+=v[i];
			
		}
		cout<<maxx<<endl;
		
	}
	return 0;
}

