#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,x;
bool flag=true;
int a[5005];
int aaa=1;
int b[20];
int maxn=-1e9;
int sum;
void dfs(int i,int start,int tot){
	if(sum>=i){
		if(tot>maxn){
			aaa++;
			aaa%=MOD;
		}
		return;
	}
	for(int j=start;j<=n;j++){
		sum++;
		x=maxn;
		b[sum]=a[j];
		maxn=max(maxn,a[j]*2);
		dfs(i,j+1,tot+a[j]);
		sum--; 
		maxn=x;
	}
	return ;
}
long long k=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,1,0);
		maxn=-1e9;
	}
	cout<<aaa%MOD-1;
	return 0;
}
