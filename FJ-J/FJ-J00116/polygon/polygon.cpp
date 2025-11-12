#include<bits/stdc++.h>
using namespace std;
int n,a[5001],b[5001],c[5001],vis[5001],cnt;
bool f;
void dfs(int x,int ma){
	if(x>ma){
		int sum=0;
		for(int i=1;i<ma;i++){
			sum+=b[i];
		}
		if(sum>b[ma]){
			cnt++;
		}
		else{
			f=1;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&i>c[x-1]){
			b[x]=a[i];
			c[x]=i;
			vis[i]=1;
			dfs(x+1,ma);
			b[x]=0;
			c[x]=0;
			vis[i]=0;
			if(f){
				f=0;
				break;
			}
		}
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
	}
	stable_sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(1,i);
	}
	cout<<cnt;
	return 0;
}
