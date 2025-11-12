#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int a[N],vis[N],ord[N],n,m,ans;
string p;
bool check(){
	int s=0,k=0;
	for(int i=1;i<=n;i++){
		if(p[i-1]=='0')s++;
		else if(s>=a[ord[i]])s++;
		else k++;
		if(n-s<m)break;
	}
	return k>=m;
}
void dfs(int step){
	if(step==n){
		if(check()){
			ans++;
			//for(int i=1;i<=n;i++)printf("%d ",ord[i]);
			//cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1,ord[step+1]=i;
		dfs(step+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>p;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
