#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int mod=998244353;
int n;
int a[500100];
int st[500100];
vector<int>v;

int sum;
void dfs(int x,int ma,int num){
	if(num>ma*2&&v.size()>=3){
		sum++;
		sum%=mod;
	}
	if(x==n+1) return ;
	for(int i=x;i<=n;i++){
		if(st[i]==0){
			
			
			v.push_back(a[i]);
			dfs(i+1,max(ma,a[i]),num+a[i]);
			v.pop_back();
			
			
		}
		else continue;
	}
	
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<sum;
	
	return 0;
}
