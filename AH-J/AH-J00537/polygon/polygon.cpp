#include<bits/stdc++.h>
using namespace std;
int n,a[10010];
unsigned long long cnt=0;
void dfs(int k,long long he,int maxx,int s){
	if(k>=n)return;
	if(he+a[k]-max(maxx,a[k])>max(maxx,a[k])&&s+1>=3){
		cnt=cnt+1;
	}
	dfs(k+1,he+a[k],max(maxx,a[k]),s+1);
	dfs(k+1,he,maxx,s);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	dfs(0,0,0,0);
	cnt=cnt%998244353;
	cout<<cnt;
	return 0;
}
