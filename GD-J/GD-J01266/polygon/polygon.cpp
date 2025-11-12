#include<bits/stdc++.h>
using namespace std;
int a[1005],n,num,sum,b[1005],g[1005],ans;
void dfs(int x,int m){
	if(x==m+1){
		if(sum>b[m]*2){
//			cout<<'\n';
//			cout<<sum<<' '<<b[m]*2+1<<'\n';
//			for(int i=1;i<=m;i++){
//				cout<<b[i]<<' ';
//			}
//			cout<<'\n';
			ans++;
		}
//		cout<<"================="<<'\n'; 
//		for(int i=1;i<=m;i++){
//				cout<<b[i]<<' ';
//		}
//		cout<<'\n';
//		cout<<sum<<' '<<b[m]*2+1<<'\n';
		return ;
	}
	for(int i=b[x-1]+1;i<=n;i++){
		if(g[i]==0){
			sum+=i;
			b[x]=i;
			g[i]++;
			dfs(x+1,m);
			b[x]=0;
			g[i]--;
			sum-=i;
		}
	}
}
int main() {
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		sum=0;
		dfs(1,i);
	}
	cout<<ans;
	return 0;
}
