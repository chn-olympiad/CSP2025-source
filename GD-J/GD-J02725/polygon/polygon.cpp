#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[5010];
bool b[5010];
long long sum=0;

void dfs(int f,int s,int m,int st){
	if(s>2*m)sum++,sum%=998244353;
	if(st>n||f>=n)return;
	for(int i=st;i<=n;i++){
		if(!b[i]){
			b[i]=true;
			dfs(f+1,s+a[i],max(m,a[i]),i+1);
			b[i]=false;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,1);
	cout<<sum;
	return 0;
}
