#include<bits/stdc++.h>
using namespace std;
unsigned n;
unsigned long cou;
unsigned a[5005];
void dfs(unsigned ma,unsigned k,unsigned long s,bool c){
	if(k==n+1)return ;
	if(ma*2<s&&c)cou=(cou+1)%998244353;
	dfs(max(ma,a[k]),k+1,s+a[k],1);
	dfs(ma,k+1,s,0);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(unsigned i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,0,0);
	cout<<cou;
	return 0;
}
