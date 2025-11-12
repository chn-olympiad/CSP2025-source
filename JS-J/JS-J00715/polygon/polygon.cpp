#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c[N];
int qjh[N];
bool cmp(int x,int y){
	return x<y;
}
int ans=0;
int n;
void dfs(int now,int value){
	if(now>n)return ;
	dfs(now+1,value);
	if(value+c[now]>2*c[now]){
		++ans;
		ans%=998244353;
	}
	dfs(now+1,value+c[now]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n,cmp);
	for(int i=1;i<=n;i++){
		qjh[i]=qjh[i-1]+c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
