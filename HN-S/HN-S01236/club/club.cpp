#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[100009][4];
ll maxn;
ll v[100009];
ll t;
void dfs(ll num,ll sum,ll x,ll y,ll z){
	if(num==n){
		maxn=max(maxn,sum);
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(x+1<=n/2)dfs(num+1,sum+a[i][1],x+1,y,z);
			if(y+1<=n/2)dfs(num+1,sum+a[i][2],x,y+1,z);
			if(z+1<=n/2)dfs(num+1,sum+a[i][3],x,y,z+1);
			v[i]=0;
		}
	}
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++){
		memset(v,0,sizeof(v));	
		maxn=0;
		cin>>n;
		bool flag=1;
		ll b[100009];
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
			if(a[i][3]!=0||a[i][2]!=0)flag=0;
		}
		if(flag){
			sort(b+1,b+1+n,cmp);
			for(ll i=1;i<=n/2;i++){
				maxn+=b[i];
			}
		}
		else dfs(0,0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

