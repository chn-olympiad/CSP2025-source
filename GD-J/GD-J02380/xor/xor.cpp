#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int N=5e5+5;
int pre[N],a[N];
int n,k,ans;
bool f1,f2;
vector<int> ran[N];
void dfs(int d,int cnt){
	ans=max(ans,cnt);
	for(int i:ran[d])
		dfs(d+i+1,cnt+1);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	For(i,1,n){
		cin>>a[i];
		if(a[i]!=1) f1=1;
		if(a[i]>=2) f2=1;
		pre[i]=pre[i-1]^a[i];
	}
	if(!f1) return cout<<n/2,0;
	if(!f2){
		if(k==1)
			For(i,1,n){
				if(a[i]==k)
					ans++;
			}
		else
			For(i,1,n){
				if(a[i]==k)
					ans++;
				if(a[i]==1&&a[i+1]==1)
					ans++,i++;
			}
		cout<<ans;
		return 0;
	}
	For(i,1,n){
		For(j,0,n-i){
			if((pre[i+j]^pre[i-1])==k){
				ran[i].push_back(j);
			}
		}
	}
	For(i,1,n)
		dfs(i,0);
	cout<<ans;
	return 0;
}
