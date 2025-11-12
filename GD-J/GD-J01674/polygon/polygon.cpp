#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll modd=998244353;
int n=0;
ll res=0;
vector<int>a;
vector<int>c; 
//多边形边数和当前已有边数，最大值下标 
void dfs(int s,int have,int summ,int mx)
{
	
	if(have>=s){
		if(summ>a[mx]*2){
			res++;
			res%=modd;
		}
		return ; 
	}
	
	//选取后面元素 
	for(int i=mx+1;i<=n;i++){
		dfs(s,have+1,summ+a[i],i);
		
	}
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	

	cin>>n;
	a.resize(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	//排序 
	sort(a.begin()+1,a.end(),less<int>());
	
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0);
	}
	res%=modd;
	
	cout<<res;
	
	
	
	return 0;
}
