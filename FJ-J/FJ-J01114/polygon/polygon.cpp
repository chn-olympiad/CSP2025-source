#include <iostream>
#include <vector>
using namespace std;
const int N=998244353;
int counts=0;//方案数
int n;
long long sum=0;//总和 
long long maxn=0;//最大 
int res=0;//数量 
vector<int> vis;
vector<long long> a;
void dfs(int x,int j)
{
	if(res==x){
		if(sum>(maxn*2)){
			counts=(counts+1)%N;
		}
		return;
	}
	for(int i=(j+1);i<n;i++){
		if(vis[i]==0){
			sum=sum+a[i];
			int cur=maxn;
			maxn=max(maxn,a[i]);
			res=res+1;
			vis[i]=1;
			dfs(x,i);
			vis[i]=0;
			res=res-1;
			maxn=cur;
			sum=sum-a[i];
		}
	}
	return;
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=0;i<n;i++){
		long long u;
		cin>>u;
		a.push_back(u);
		vis.push_back(0);
	}
	for(int x=3;x<=n;x++){
		maxn=0;
		sum=0;
		res=0;
		dfs(x,-1);
	}
	cout<<counts;
	return 0;
}
