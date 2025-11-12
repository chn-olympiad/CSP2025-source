#include<bits/stdc++.h>
using namespace std;
int a[5007],n;
long long s;
vector<int> b={0,0};
bool cmp(int a,int b){
	return a>b;
}
void dfs(long long ma,int i,int x,int c){
	ma+=x;
	if(ma>c){
		s++;
		s+=(n-i)*(n-i+1)/2;
		s%=998244353;
		return;
	}
	if(ma+a[n]>c){
		s+=(n-i)*(n-i+1)/2;
		s%=998244353;
		return;
	} 
	for(int j=i+1;j<=n;j++){
		dfs(ma,j,a[j],c);
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f&&a[i]!=1) f=0;
	}
	if(f){
		cout<<((1ll*(n-2)%998244353*(n-1)%998244353)%998244353)/2;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dfs(0,i,0,a[i]);
	}
	cout<<s;
	return 0;
} 
