#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ch[5001],ans;
void dfs(int k,int step){
	if(k>=4){
		int mx=0,h=0;
		for(int i=1;i<k;i++){
			mx=max(mx,ch[i]);
			h+=ch[i];
		}
		if(h>mx*2) ans++;
		ans%=998244353;
	}
	for(int i=step;i<=n;i++){
		ch[k]=a[i];
		dfs(k+1,i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<ans;
	return 0;
} 
