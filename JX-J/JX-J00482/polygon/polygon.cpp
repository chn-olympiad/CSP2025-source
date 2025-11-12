#include<bits/stdc++.h>
using namespace std;
const int N=501;
int n,res,qans;
int a[N];
void dfs(int u,int maxp,int ans,int k){
	if(u>n)return;
	if(ans>qans)return;
	if(k>=3){
		if(ans>2*maxp){
			res++;
		}
	}
	for(int i=u+1;i<=n;i++){
		int r=max(maxp,a[i]);
		dfs(i,r,ans+a[i],k+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qans+=a[i];
	}
	dfs(0,-100,0,0);
	cout<<res<<endl;
}
