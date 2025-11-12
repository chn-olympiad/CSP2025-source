#include<bits/stdc++.h>
using namespace std;
int a[20],vis[20];
int n,ans=0;
vector<int> g;
bool check(){
	int sum=0;
	sort(g.begin(),g.end());
	int mmm=g[2]; 
	for(int i=0;i<=2;i++) sum+=g[i];
	if(sum>2*mmm) return true;
	else return false;
}
void dfs(int x,int step){
	g.push_back(a[x]);
	vis[x]=1;
	if(step==3){
		if(check()==true){
			g.clear();
			ans++;
			return ;
		}
	}
	for(int i=x+1;i<=n;i++){
		if(vis[i]==0){
			dfs(i,step++);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	//task1
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int maxn=a[3];
		int sum=a[1]+a[2]+a[3];
		if(sum>maxn*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	//task2
	if(n>3&&n<=10){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-2;i++){
			dfs(i,1);
		}
		cout<<ans;
	}
	return 0;
}
