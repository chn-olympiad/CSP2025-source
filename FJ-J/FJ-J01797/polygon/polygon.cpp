#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[5001];

void BFS(int q,int sum,int bs,int x){
	if(x-q==bs){
		if(sum>a[x]*2) ans++;
		return;
	}
	for(int i=1;i<=n-bs-q+1;i++) BFS(q+i-1,sum+a[i+x],bs,i+x);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) BFS(0,0,i,0);
	cout<<ans%998244353;
	return 0;
}
