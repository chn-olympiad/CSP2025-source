#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int m,vis[5010];
long long ans;
vector<int> a;
void dfs(int i,long long sum,int b,int curLenth){
	for(int j=i;j<a.size();j++){
		int lb=b;
		sum+=a[i],b=max(b,a[i]);
		if(sum>2*b&&curLenth>=3){
			ans=ans+1%N;
			return;
		}
		if(!vis[i]){
			vis[i]=1;
			dfs(i+1,sum,b,curLenth+1);
			sum-=a[i],b=lb;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=0,x;i<m;i++)cin>>x,a.push_back(x);
	sort(a.begin(),a.end());
	dfs(0,0,0,0);
	cout<<ans%N;
}
