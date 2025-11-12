#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
const int MOD=998244353;
int n,a[N];
ll cnt;
bool vis[N];
void choose(int k,int l,int j,int sum,int maxw){
	if(k==l&&sum>=(2*maxw)){
		cnt++;
		return;
	}
	for(int i = j+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			choose(k+1,l,i,sum+a[i],a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		choose(0,i,0,0,0);
	}
	cout<<cnt%MOD;
	return 0;
}

