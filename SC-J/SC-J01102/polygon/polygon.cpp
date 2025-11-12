#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long o=-2,s;
void dfs(int num,int maxx,int sum,int num1){
	if(num1>=3&&sum>2*maxx){
		++o;
		o=o%998244353;
	}
	if(num1+(n-num)<3||num==n||a[num]*2>=s) return;
	dfs(num+1,maxx,sum,num1);
	dfs(num+1,max(maxx,a[num+1]),sum+a[num+1],num1+1);
	
}
int main(){
	freopen(" number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	dfs(1,a[1],a[1],1);
	cout<<o;
	return 0;
}