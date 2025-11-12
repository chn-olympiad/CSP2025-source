#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
bool y[5001];
bool cmp(int a,int b){return a>b;}
void dfs(bool x[5001],int i,int maxx,int cnt,int s){
	if(i>n){
		if(s>=3&&!(2*maxx>=cnt)) ans++;
		return;
	}
//	if()
	x[i]=0;
	dfs(x,i+1,maxx,cnt,s);
	s++;
	cnt+=a[i];
	maxx=max(maxx,a[i]);
	x[i]=1;
	dfs(x,i+1,maxx,cnt,s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	dfs(y,1,0,0,0);
	cout<<ans;
}
