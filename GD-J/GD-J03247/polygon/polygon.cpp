#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=998244353;
const int N=5010;
int a[N],b[N];
bool v[N];
int n;
int ans;
void dfs(int num,bool xx){
	if(num>n)return ;
	if(num>=3&&xx==1){
		int sum=0,maxx=INT_MIN;
		for(int i=1;i<=num;i++){
			sum+=b[i];
			maxx=max(maxx,b[i]);
		}
		if(sum>2*maxx){
			ans++;
			ans%=MOD;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==1)continue;
		v[i]=1;
		b[num]=a[i];
		dfs(num+1,0);
		dfs(num+1,1);
		//v[i]=0;
	}
	
	return ;
	
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==3){
		int x,y,z;
		cin>>x>>y>>z;
		if((x+y+z)>2*max(max(x,y),z)){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

