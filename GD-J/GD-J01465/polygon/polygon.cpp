#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans,x[5001],b,y[5001];
void dfs(int d,int m,int cnt,int s){
	if(d>b)return;
	dfs(d+1,m,cnt,s);
	if(x[d]>m)m=x[d];
	for(int i=1;i<=y[d];i++){
		cnt+=x[d];
		s++;
		if(cnt>m*2&&s>2)ans=(ans+1)%998244353;
		dfs(d+1,m,cnt,s);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]!=x[b-1])x[b++]=a[i];
		y[b-1]++;
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
